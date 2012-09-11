/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *  (C) 2012 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include "ptl_impl.h"

#ifdef ENABLE_CHECKPOINTING
#error Checkpointing not implemented
#endif

#define EQ_COUNT 100
#define NID_KEY  "NID"
#define PID_KEY  "PID"
#define PTI_KEY  "PTI"
#define PTIC_KEY "PTIC"

static int ptl_init(MPIDI_PG_t *pg_p, int pg_rank, char **bc_val_p, int *val_max_sz_p);
static int ptl_finalize(void);
static int get_business_card(int my_rank, char **bc_val_p, int *val_max_sz_p);
static int connect_to_root(const char *business_card, MPIDI_VC_t *new_vc);
static int vc_init(MPIDI_VC_t *vc);
static int vc_destroy(MPIDI_VC_t *vc);
static int vc_terminate(MPIDI_VC_t *vc);

static ptl_process_t my_ptl_id;

MPID_nem_netmod_funcs_t MPIDI_nem_portals4_funcs = {
    ptl_init,
    ptl_finalize,
    MPID_nem_ptl_poll,
    get_business_card,
    connect_to_root,
    vc_init,
    vc_destroy,
    vc_terminate,
    MPID_nem_ptl_anysource_iprobe,
    MPID_nem_ptl_anysource_improbe
};

static MPIDI_Comm_ops_t comm_ops = {
    MPID_nem_ptl_recv_posted,   /* recv_posted */

    MPID_nem_ptl_isend,         /* send */
    MPID_nem_ptl_isend,         /* rsend */
    MPID_nem_ptl_issend,        /* ssend */
    MPID_nem_ptl_isend,         /* isend */
    MPID_nem_ptl_isend,         /* irsend */
    MPID_nem_ptl_issend,        /* issend */

    NULL,                       /* send_init */
    NULL,                       /* bsend_init */
    NULL,                       /* rsend_init */
    NULL,                       /* ssend_init */
    NULL,                       /* startall */

    MPID_nem_ptl_cancel_send,   /* cancel_send */
    MPID_nem_ptl_cancel_recv,   /* cancel_recv */

    MPID_nem_ptl_probe,         /* probe */
    MPID_nem_ptl_iprobe,        /* iprobe */
    MPID_nem_ptl_improbe        /* improbe */
};


#undef FUNCNAME
#define FUNCNAME ptl_init
#undef FCNAME
#define FCNAME MPIDI_QUOTE(FUNCNAME)
static int ptl_init(MPIDI_PG_t *pg_p, int pg_rank, char **bc_val_p, int *val_max_sz_p)
{
    int mpi_errno = MPI_SUCCESS;
    int ret;
    MPIDI_STATE_DECL(MPID_STATE_PTL_INIT);

    MPIDI_FUNC_ENTER(MPID_STATE_PTL_INIT);

    /* first make sure that our private fields in the vc fit into the area provided  */
    MPIU_Assert(sizeof(MPID_nem_ptl_vc_area) <= MPID_NEM_VC_NETMOD_AREA_LEN);

    /* init portals */
    ret = PtlInit();
    MPIU_ERR_CHKANDJUMP(ret, mpi_errno, MPI_ERR_OTHER, "**ptlinit");
    
    ret = PtlNIInit(PTL_IFACE_DEFAULT, PTL_NI_MATCHING | PTL_NI_PHYSICAL,
                    PTL_PID_ANY, NULL, NULL, &MPIDI_nem_ptl_ni);
    MPIU_ERR_CHKANDJUMP(ret, mpi_errno, MPI_ERR_OTHER, "**ptlniinit");

    ret = PtlEQAlloc(MPIDI_nem_ptl_ni, EQ_COUNT, &MPIDI_nem_ptl_eq);
    MPIU_ERR_CHKANDJUMP(ret, mpi_errno, MPI_ERR_OTHER, "**ptleqalloc");

    /* allocate portal for matching messages */
    ret = PtlPTAlloc(MPIDI_nem_ptl_ni, PTL_PT_ONLY_USE_ONCE | PTL_PT_ONLY_TRUNCATE | PTL_PT_FLOW_CONTROL, MPIDI_nem_ptl_eq,
                     PTL_PT_ANY, &MPIDI_nem_ptl_pt);
    MPIU_ERR_CHKANDJUMP(ret, mpi_errno, MPI_ERR_OTHER, "**ptlptalloc");

    /* allocate portal for MPICH control messages */
    ret = PtlPTAlloc(MPIDI_nem_ptl_ni, PTL_PT_ONLY_USE_ONCE | PTL_PT_ONLY_TRUNCATE | PTL_PT_FLOW_CONTROL, MPIDI_nem_ptl_eq,
                     PTL_PT_ANY, &MPIDI_nem_ptl_control_pt);

    ret = PtlGetId(MPIDI_nem_ptl_ni, &my_ptl_id);
    MPIU_ERR_CHKANDJUMP(ret, mpi_errno, MPI_ERR_OTHER, "**ptlgetid");
    MPIU_DBG_MSG_FMT(CH3_CHANNEL, VERBOSE, (MPIU_DBG_FDEST, "Allocated NI and PT id=(%#x,%#x) pt=%#x",
                                            my_id.phys.nid, my_id.phys.pid, MPIDI_nem_ptl_pt));

    /* create business card */
    mpi_errno = get_business_card(pg_rank, bc_val_p, val_max_sz_p);
    if (mpi_errno) MPIU_ERR_POP(mpi_errno);

    mpi_errno = MPIDI_CH3I_Register_anysource_notification(MPID_nem_ptl_anysource_posted, MPID_nem_ptl_anysource_matched);
    if (mpi_errno) MPIU_ERR_POP(mpi_errno);

    /* init other modules */
    mpi_errno = MPID_nem_ptl_poll_init();
    if (mpi_errno) MPIU_ERR_POP(mpi_errno);

    mpi_errno = MPID_nem_ptl_send_init();
    if (mpi_errno) MPIU_ERR_POP(mpi_errno);
    
 fn_exit:
    MPIDI_FUNC_EXIT(MPID_STATE_PTL_INIT);
    return mpi_errno;
 fn_fail:
    goto fn_exit;
}

#undef FUNCNAME
#define FUNCNAME ptl_finalize
#undef FCNAME
#define FCNAME MPIU_QUOTE(FUNCNAME)
static int ptl_finalize(void)
{
    int mpi_errno = MPI_SUCCESS;
    int ret;
    MPIDI_STATE_DECL(MPID_STATE_PTL_FINALIZE);
    MPIDI_FUNC_ENTER(MPID_STATE_PTL_FINALIZE);

    /* shut down other modules */
    mpi_errno = MPID_nem_ptl_send_finalize();
    if (mpi_errno) MPIU_ERR_POP(mpi_errno);

    mpi_errno = MPID_nem_ptl_poll_finalize();
    if (mpi_errno) MPIU_ERR_POP(mpi_errno);

    /* shut down portals */
    ret = PtlPTFree(MPIDI_nem_ptl_ni, MPIDI_nem_ptl_pt);
    MPIU_ERR_CHKANDJUMP(ret, mpi_errno, MPI_ERR_OTHER, "**ptlptfree");

    ret = PtlNIFini(MPIDI_nem_ptl_ni);
    MPIU_ERR_CHKANDJUMP(ret, mpi_errno, MPI_ERR_OTHER, "**ptlnifini");

    PtlFini();

 fn_exit:
    MPIDI_FUNC_EXIT(MPID_STATE_PTL_FINALIZE);
    return mpi_errno;
 fn_fail:
    goto fn_exit;
}




#undef FUNCNAME
#define FUNCNAME get_business_card
#undef FCNAME
#define FCNAME MPIDI_QUOTE(FUNCNAME)
static int get_business_card(int my_rank, char **bc_val_p, int *val_max_sz_p)
{
    int mpi_errno = MPI_SUCCESS;
    int str_errno = MPIU_STR_SUCCESS;
    int ret;
    MPIDI_STATE_DECL(MPID_STATE_GET_BUSINESS_CARD);

    MPIDI_FUNC_ENTER(MPID_STATE_GET_BUSINESS_CARD);

    str_errno = MPIU_Str_add_binary_arg(bc_val_p, val_max_sz_p, NID_KEY, (char *)&my_ptl_id.phys.nid, sizeof(my_ptl_id.phys.nid));
    if (str_errno) {
        MPIU_ERR_CHKANDJUMP(str_errno == MPIU_STR_NOMEM, mpi_errno, MPI_ERR_OTHER, "**buscard_len");
        MPIU_ERR_SETANDJUMP(mpi_errno, MPI_ERR_OTHER, "**buscard");
    }
    str_errno = MPIU_Str_add_binary_arg(bc_val_p, val_max_sz_p, PID_KEY, (char *)&my_ptl_id.phys.pid, sizeof(my_ptl_id.phys.pid));
    if (str_errno) {
        MPIU_ERR_CHKANDJUMP(str_errno == MPIU_STR_NOMEM, mpi_errno, MPI_ERR_OTHER, "**buscard_len");
        MPIU_ERR_SETANDJUMP(mpi_errno, MPI_ERR_OTHER, "**buscard");
    }
    str_errno = MPIU_Str_add_binary_arg(bc_val_p, val_max_sz_p, PTI_KEY, (char *)&MPIDI_nem_ptl_pt, sizeof(MPIDI_nem_ptl_pt));
    if (str_errno) {
        MPIU_ERR_CHKANDJUMP(str_errno == MPIU_STR_NOMEM, mpi_errno, MPI_ERR_OTHER, "**buscard_len");
        MPIU_ERR_SETANDJUMP(mpi_errno, MPI_ERR_OTHER, "**buscard");
    }
    str_errno = MPIU_Str_add_binary_arg(bc_val_p, val_max_sz_p, PTIC_KEY, (char *)&MPIDI_nem_ptl_control_pt,
                                        sizeof(MPIDI_nem_ptl_control_pt));
    if (str_errno) {
        MPIU_ERR_CHKANDJUMP(str_errno == MPIU_STR_NOMEM, mpi_errno, MPI_ERR_OTHER, "**buscard_len");
        MPIU_ERR_SETANDJUMP(mpi_errno, MPI_ERR_OTHER, "**buscard");
    }

 fn_exit:
    MPIDI_FUNC_EXIT(MPID_STATE_GET_BUSINESS_CARD);
    return mpi_errno;
 fn_fail:
    goto fn_exit;
}

#undef FUNCNAME
#define FUNCNAME connect_to_root
#undef FCNAME
#define FCNAME MPIDI_QUOTE(FUNCNAME)
static int connect_to_root(const char *business_card, MPIDI_VC_t *new_vc)
{
    int mpi_errno = MPI_SUCCESS;
    MPIDI_STATE_DECL(MPID_STATE_CONNECT_TO_ROOT);

    MPIDI_FUNC_ENTER(MPID_STATE_CONNECT_TO_ROOT);

    MPIU_ERR_SETFATAL(mpi_errno, MPI_ERR_OTHER, "**notimpl");

 fn_exit:
    MPIDI_FUNC_EXIT(MPID_STATE_CONNECT_TO_ROOT);
    return mpi_errno;

 fn_fail:
    goto fn_exit;
}

#undef FUNCNAME
#define FUNCNAME vc_init
#undef FCNAME
#define FCNAME MPIDI_QUOTE(FUNCNAME)
static int vc_init(MPIDI_VC_t *vc)
{
    int mpi_errno = MPI_SUCCESS;
    MPIDI_CH3I_VC *const vc_ch = VC_CH(vc);
    MPID_nem_ptl_vc_area *const vc_ptl = VC_PTL(vc);
    MPIDI_STATE_DECL(MPID_STATE_VC_INIT);

    MPIDI_FUNC_ENTER(MPID_STATE_VC_INIT);

    /* */
    MPIU_Assert(vc->lpid < NPTL_MAX_PROCS);
    
    vc->sendNoncontig_fn   = MPID_nem_ptl_SendNoncontig;
    vc_ch->iStartContigMsg = MPID_nem_ptl_iStartContigMsg;
    vc_ch->iSendContig     = MPID_nem_ptl_iSendContig;

    if (MPIR_PARAM_COMM_OVERRIDES) /* allow feature to be disabled at runtime */
        vc->comm_ops = &comm_ops;

    vc_ch->next = NULL;
    vc_ch->prev = NULL;

    vc_ptl->id_initialized = FALSE;
    vc_ptl->num_queued_sends = 0;

    MPIDI_FUNC_EXIT(MPID_STATE_VC_INIT);
    return mpi_errno;
}

#undef FUNCNAME
#define FUNCNAME vc_destroy
#undef FCNAME
#define FCNAME MPIDI_QUOTE(FUNCNAME)
static int vc_destroy(MPIDI_VC_t *vc)
{
    int mpi_errno = MPI_SUCCESS;

    /* currently do nothing */

    return mpi_errno;
}


#undef FUNCNAME
#define FUNCNAME MPID_nem_ptl_get_id_from_bc
#undef FCNAME
#define FCNAME MPIU_QUOTE(FUNCNAME)
int MPID_nem_ptl_get_id_from_bc(const char *business_card, ptl_process_t *id, ptl_pt_index_t *pt, ptl_pt_index_t *ptc)
{
    int mpi_errno = MPI_SUCCESS;
    int ret;
    int len;
    MPIDI_STATE_DECL(MPID_STATE_MPID_NEM_PTL_GET_ID_FROM_BC);

    MPIDI_FUNC_ENTER(MPID_STATE_MPID_NEM_PTL_GET_ID_FROM_BC);

    ret = MPIU_Str_get_binary_arg(business_card, NID_KEY, (char *)&id->phys.nid, sizeof(id->phys.nid), &len);
    MPIU_ERR_CHKANDJUMP(ret != MPIU_STR_SUCCESS || len != sizeof(id->phys.nid), mpi_errno, MPI_ERR_OTHER, "**badbusinesscard");

    ret = MPIU_Str_get_binary_arg(business_card, PID_KEY, (char *)&id->phys.pid, sizeof(id->phys.pid), &len);
    MPIU_ERR_CHKANDJUMP(ret != MPIU_STR_SUCCESS || len != sizeof(id->phys.pid), mpi_errno, MPI_ERR_OTHER, "**badbusinesscard");

    ret = MPIU_Str_get_binary_arg(business_card, PTI_KEY, (char *)pt, sizeof(pt), &len);
    MPIU_ERR_CHKANDJUMP(ret != MPIU_STR_SUCCESS || len != sizeof(*pt), mpi_errno, MPI_ERR_OTHER, "**badbusinesscard");

    ret = MPIU_Str_get_binary_arg(business_card, PTIC_KEY, (char *)ptc, sizeof(ptc), &len);
    MPIU_ERR_CHKANDJUMP(ret != MPIU_STR_SUCCESS || len != sizeof(*pt), mpi_errno, MPI_ERR_OTHER, "**badbusinesscard");

 fn_exit:
    MPIDI_FUNC_EXIT(MPID_STATE_MPID_NEM_PTL_GET_ID_FROM_BC);
    return mpi_errno;
 fn_fail:
    goto fn_exit;
}

#undef FUNCNAME
#define FUNCNAME vc_terminate
#undef FCNAME
#define FCNAME MPIU_QUOTE(FUNCNAME)
int vc_terminate(MPIDI_VC_t *vc)
{
    int mpi_errno = MPI_SUCCESS;
    int req_errno = MPI_SUCCESS;
    MPID_nem_ptl_vc_area *const vc_ptl = VC_PTL(vc);
    MPIDI_STATE_DECL(MPID_STATE_VC_TERMINATE);

    MPIDI_FUNC_ENTER(MPID_STATE_VC_TERMINATE);

     if (vc->state != MPIDI_VC_STATE_CLOSED) {
        /* VC is terminated as a result of a fault.  Complete
           outstanding sends with an error and terminate
           connection immediately. */
        MPIU_ERR_SET1(req_errno, MPIX_ERR_PROC_FAIL_STOP, "**comm_fail", "**comm_fail %d", vc->pg_rank);
        mpi_errno = MPID_nem_ptl_sendq_complete_with_error(vc, req_errno);
        if (mpi_errno) MPIU_ERR_POP(mpi_errno);
        mpi_errno = MPID_nem_ptl_vc_terminated(vc);
        if (mpi_errno) MPIU_ERR_POP(mpi_errno);
     } else if (vc_ptl->num_queued_sends == 0) {
         mpi_errno = MPID_nem_ptl_vc_terminated(vc);
         if (mpi_errno) MPIU_ERR_POP(mpi_errno);
     } else {
         /* the send_queued function will call vc_terminated if vc->state is
            CLOSED and the last queued send has been sent*/
     }
    
 fn_exit:
    MPIDI_FUNC_EXIT(MPID_STATE_VC_TERMINATE);
    return mpi_errno;
 fn_fail:
    goto fn_exit;
}


#undef FUNCNAME
#define FUNCNAME MPID_nem_ptl_vc_terminated
#undef FCNAME
#define FCNAME MPIDI_QUOTE(FUNCNAME)
int MPID_nem_ptl_vc_terminated(MPIDI_VC_t *vc)
{
    /* This is called when the VC is to be terminated once all queued
       sends have been sent. */
    int mpi_errno = MPI_SUCCESS;
    MPIDI_STATE_DECL(MPID_NEM_PTL_VC_TERMINATED);

    MPIDI_FUNC_ENTER(MPID_NEM_PTL_VC_TERMINATED);

    mpi_errno = MPIDI_CH3U_Handle_connection(vc, MPIDI_VC_EVENT_TERMINATED);
    if(mpi_errno) MPIU_ERR_POP(mpi_errno);

 fn_exit:
    MPIDI_FUNC_EXIT(MPID_NEM_PTL_VC_TERMINATED);
    return mpi_errno;
 fn_fail:
    MPIU_DBG_MSG_FMT(NEM_SOCK_DET, VERBOSE, (MPIU_DBG_FDEST, "failure. mpi_errno = %d", mpi_errno));
    goto fn_exit;
}

