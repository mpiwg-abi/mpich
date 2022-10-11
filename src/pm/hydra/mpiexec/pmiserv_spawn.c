/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "hydra_server.h"
#include "hydra.h"
#include "bsci.h"
#include "pmiserv.h"
#include "pmiserv_pmi.h"
#include "pmiserv_utils.h"

static struct HYD_pg *spawn_pg = NULL;
static struct HYD_exec *spawn_exec_list = NULL;

static HYD_status allocate_spawn_pg(int fd);
static HYD_status fill_exec_params(struct HYD_exec *exec, const char *execname, int nprocs,
                                   int argcnt, const char **argv,
                                   int infonum, struct PMIU_token *infos);
static HYD_status fill_preput_kvs(struct HYD_pmcd_pmi_kvs *kvs,
                                  int preput_num, struct PMIU_token *infos);
static HYD_status do_spawn(void);

static char *get_exec_path(const char *execname, const char *path);
static HYD_status parse_info_hosts(const char *host_str, struct HYD_pg *pg);

static const bool is_static = true;

HYD_status HYD_pmiserv_spawn(int fd, int pid, int pgid, struct PMIU_cmd *pmi)
{
    HYD_status status = HYD_SUCCESS;
    int pmi_errno;
    bool need_free = false;
    HYDU_FUNC_ENTER();

    status = allocate_spawn_pg(fd);
    HYDU_ERR_POP(status, "spawn failed\n");

    struct HYD_pmcd_pmi_pg_scratch *pg_scratch = spawn_pg->pg_scratch;

    int count;
    int total_args, total_info, num_preput;
    pmi_errno = PMIU_msg_get_query_spawn_sizes(pmi, &count, &total_args, &total_info, &num_preput);
    HYDU_ASSERT(!pmi_errno, status);

    const char **cmds;
    int *maxprocs;
    int *argcs;
    const char **argvs;
    int *info_counts;
    struct PMIU_token *info_keyvals, *preput_keyvals;

    cmds = MPL_malloc(count * sizeof(char *), MPL_MEM_OTHER);
    maxprocs = MPL_malloc(count * sizeof(int), MPL_MEM_OTHER);
    argcs = MPL_malloc(count * sizeof(int), MPL_MEM_OTHER);
    argvs = MPL_malloc(total_args * sizeof(char *), MPL_MEM_OTHER);
    info_counts = MPL_malloc(count * sizeof(int), MPL_MEM_OTHER);
    info_keyvals = MPL_malloc(total_info * sizeof(struct PMIU_token), MPL_MEM_OTHER);
    preput_keyvals = MPL_malloc(num_preput * sizeof(struct PMIU_token), MPL_MEM_OTHER);
    need_free = true;

    pmi_errno = PMIU_msg_get_query_spawn(pmi, cmds, maxprocs, argcs, argvs,
                                         info_counts, info_keyvals, preput_keyvals);
    HYDU_ASSERT(!pmi_errno, status);


    status = fill_preput_kvs(pg_scratch->kvs, num_preput, preput_keyvals);
    HYDU_ERR_POP(status, "spawn failed\n");

    struct HYD_exec *exec;
    exec = NULL;
    int i_argv = 0;
    int i_info = 0;
    for (int j = 0; j < count; j++) {
        if (exec == NULL) {
            status = HYDU_alloc_exec(&spawn_exec_list);
            HYDU_ERR_POP(status, "spawn failed\n");
            exec = spawn_exec_list;
            exec->appnum = j;
        } else {
            status = HYDU_alloc_exec(&exec->next);
            HYDU_ERR_POP(status, "spawn failed\n");
            exec = exec->next;
            exec->appnum = j;
        }

        status = fill_exec_params(exec, cmds[j], maxprocs[j], argcs[j], argvs + i_argv,
                                  info_counts[j], info_keyvals + i_info);
        HYDU_ERR_POP(status, "spawn failed\n");

        i_argv += argcs[j];
        i_info += info_counts[j];
    }

    status = do_spawn();
    HYDU_ERR_POP(status, "spawn failed\n");

    struct PMIU_cmd pmi_response;
    pmi_errno = PMIU_msg_set_response(pmi, &pmi_response, is_static);
    HYDU_ASSERT(!pmi_errno, status);

    status = HYD_pmiserv_pmi_reply(fd, pid, &pmi_response);
    HYDU_ERR_POP(status, "error writing PMI line\n");

    /* Cache the pre-initialized keyvals on the new proxies */
    HYD_pmiserv_bcast_keyvals(fd, pid);

  fn_exit:
    if (need_free) {
        MPL_free(cmds);
        MPL_free(maxprocs);
        MPL_free(argcs);
        MPL_free(argvs);
        MPL_free(info_counts);
        MPL_free(info_keyvals);
        MPL_free(preput_keyvals);
    }
    HYDU_FUNC_EXIT();
    return status;

  fn_fail:
    goto fn_exit;
}

/* ---- internal routines ---- */

static HYD_status allocate_spawn_pg(int fd)
{
    HYD_status status = HYD_SUCCESS;
    HYDU_FUNC_ENTER();

    struct HYD_pg *pg;
    for (pg = &HYD_server_info.pg_list; pg->next; pg = pg->next);

    status = HYDU_alloc_pg(&pg->next, pg->pgid + 1);
    HYDU_ERR_POP(status, "unable to allocate process group\n");

    status = HYD_pmcd_pmi_alloc_pg_scratch(pg->next);
    HYDU_ERR_POP(status, "unable to allocate pg scratch space\n");

    pg = pg->next;
    spawn_pg = pg;

    struct HYD_proxy *proxy;
    proxy = HYD_pmcd_pmi_find_proxy(fd);
    HYDU_ASSERT(proxy, status);

    pg->spawner_pg = proxy->pg;

  fn_exit:
    return status;
  fn_fail:
    goto fn_exit;
}

static HYD_status fill_exec_params(struct HYD_exec *exec, const char *execname, int nprocs,
                                   int argcnt, const char **argv,
                                   int infonum, struct PMIU_token *infos)
{
    HYD_status status = HYD_SUCCESS;

    struct HYD_pg *pg = spawn_pg;

    const char *path = NULL;
    /* Info keys */
    for (int i = 0; i < infonum; i++) {
        if (!strcmp(infos[i].key, "path")) {
            path = infos[i].val;
        } else if (!strcmp(infos[i].key, "wdir")) {
            exec->wdir = MPL_strdup(infos[i].val);
        } else if (!strcmp(infos[i].key, "host") || !strcmp(infos[i].key, "hosts")) {
            status = parse_info_hosts(infos[i].val, pg);
            HYDU_ERR_POP(status, "failed spawn\n");
        } else if (!strcmp(infos[i].key, "hostfile")) {
            pg->user_node_list = NULL;
            status =
                HYDU_parse_hostfile(infos[i].val, &pg->user_node_list, HYDU_process_mfile_token);
            HYDU_ERR_POP(status, "error parsing hostfile\n");
        } else {
            /* Unrecognized info key; ignore */
        }
    }

    status = HYDU_correct_wdir(&exec->wdir);
    HYDU_ERR_POP(status, "unable to correct wdir\n");

    exec->exec[0] = get_exec_path(execname, path);
    for (int i = 0; i < argcnt; i++) {
        exec->exec[i + 1] = MPL_strdup(argv[i]);
    }
    exec->exec[argcnt + 1] = NULL;

    exec->proc_count = nprocs;

    /* It is not clear what kind of environment needs to get
     * passed to the spawned process. Don't set anything here, and
     * let the proxy do whatever it does by default. */
    exec->env_prop = NULL;

    struct HYD_env *env;
    status = HYDU_env_create(&env, "PMI_SPAWNED", "1");
    HYDU_ERR_POP(status, "unable to create PMI_SPAWNED environment\n");
    exec->user_env = env;

  fn_exit:
    return status;
  fn_fail:
    goto fn_exit;
}

static HYD_status fill_preput_kvs(struct HYD_pmcd_pmi_kvs *kvs,
                                  int preput_num, struct PMIU_token *infos)
{
    HYD_status status = HYD_SUCCESS;

    for (int i = 0; i < preput_num; i++) {
        int ret;
        status = HYD_pmcd_pmi_add_kvs(infos[i].key, infos[i].val, kvs, &ret);
        HYDU_ERR_POP(status, "unable to add key pair to kvs\n");
    }

  fn_exit:
    return status;
  fn_fail:
    goto fn_exit;
}

static HYD_status do_spawn(void)
{
    HYD_status status = HYD_SUCCESS;

    struct HYD_pg *pg = spawn_pg;
    struct HYD_exec *exec_list = spawn_exec_list;

    /* Initialize the proxy stash, so it can be freed if we jump to exit */
    struct HYD_string_stash proxy_stash;
    HYD_STRING_STASH_INIT(proxy_stash);

    pg->pg_process_count = 0;
    for (struct HYD_exec * exec = exec_list; exec; exec = exec->next) {
        pg->pg_process_count += exec->proc_count;
    }

    /* PMI-v2 kvs-fence */
    status = HYD_pmiserv_epoch_init(pg);
    HYDU_ERR_POP(status, "unable to init epoch\n");

    /* Create the proxy list */
    if (pg->user_node_list) {
        status = HYDU_create_proxy_list(exec_list, pg->user_node_list, pg, false);
        HYDU_ERR_POP(status, "error creating proxy list\n");
    } else {
        status = HYDU_create_proxy_list(exec_list, HYD_server_info.node_list, pg, false);
        HYDU_ERR_POP(status, "error creating proxy list\n");
    }
    HYDU_free_exec_list(exec_list);

    pg->pg_core_count = 0;
    if (pg->user_node_list) {
        for (struct HYD_node * node = pg->user_node_list; node; node = node->next) {
            pg->pg_core_count += node->core_count;
        }
    } else {
        for (struct HYD_proxy * proxy = pg->proxy_list; proxy; proxy = proxy->next) {
            pg->pg_core_count += proxy->node->core_count;
        }
    }

    int pgid = pg->pgid;

    char *control_port;
    status = HYDU_sock_create_and_listen_portstr(HYD_server_info.user_global.iface,
                                                 HYD_server_info.localhost,
                                                 HYD_server_info.port_range, &control_port,
                                                 HYD_pmcd_pmiserv_control_listen_cb,
                                                 (void *) (size_t) pgid);
    HYDU_ERR_POP(status, "unable to create PMI port\n");
    if (HYD_server_info.user_global.debug)
        HYDU_dump(stdout, "Got a control port string of %s\n", control_port);

    /* Go to the last PG */
    for (pg = &HYD_server_info.pg_list; pg->next; pg = pg->next);

    status = HYD_pmcd_pmi_fill_in_proxy_args(&proxy_stash, control_port, pgid);
    HYDU_ERR_POP(status, "unable to fill in proxy arguments\n");
    MPL_free(control_port);

    status = HYD_pmcd_pmi_fill_in_exec_launch_info(pg);
    HYDU_ERR_POP(status, "unable to fill in executable arguments\n");

    status = HYDT_bsci_launch_procs(proxy_stash.strlist, pg->proxy_list, HYD_FALSE, NULL);
    HYDU_ERR_POP(status, "launcher cannot launch processes\n");

  fn_exit:
    HYD_STRING_STASH_FREE(proxy_stash);
    HYDU_FUNC_EXIT();
    return status;
  fn_fail:
    goto fn_exit;
}

/* utilities */

static char *get_exec_path(const char *execname, const char *path)
{
    if (path == NULL) {
        return MPL_strdup(execname);
    } else {
        char *buf;
        int len_path = strlen(path);
        int len_name = strlen(execname);
        int len = len_path + len_name + 2;
        buf = MPL_malloc(len, MPL_MEM_OTHER);
        if (buf) {
            strcpy(buf, path);
            strcpy(buf + len_path, "/");
            strcpy(buf + len_path + 1, execname);
        }
        return buf;
    }
}

static HYD_status parse_info_hosts(const char *host_str, struct HYD_pg *pg)
{
    HYD_status status = HYD_SUCCESS;

    pg->user_node_list = NULL;

    char *s = MPL_strdup(host_str);
    char *saveptr;
    char *host = strtok_r(s, ",", &saveptr);
    while (host) {
        status = HYDU_process_mfile_token(host, 1, &pg->user_node_list);
        HYDU_ERR_POP(status, "error creating node list\n");
        host = strtok_r(NULL, ",", &saveptr);
    }
    MPL_free(s);

  fn_exit:
    return status;
  fn_fail:
    goto fn_exit;
}