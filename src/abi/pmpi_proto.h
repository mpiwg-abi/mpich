/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef PMPI_PROTO_H_INCLUDED
#define PMPI_PROTO_H_INCLUDED

/* Begin Prototypes */

int PMPI_Type_create_f90_integer(int r, PMPI_Datatype *newtype);
int PMPI_Type_create_f90_real(int p, int r, PMPI_Datatype *newtype);
int PMPI_Type_create_f90_complex(int p, int r, PMPI_Datatype *newtype);
int PMPI_Attr_delete(PMPI_Comm comm, int keyval);
int PMPI_Attr_get(PMPI_Comm comm, int keyval, void *attribute_val, int *flag);
int PMPI_Attr_put(PMPI_Comm comm, int keyval, void *attribute_val);
int PMPI_Comm_create_keyval(PMPI_Comm_copy_attr_function *comm_copy_attr_fn,
                            PMPI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
                            void *extra_state);
int PMPI_Comm_delete_attr(PMPI_Comm comm, int comm_keyval);
int PMPI_Comm_free_keyval(int *comm_keyval);
int PMPI_Comm_get_attr(PMPI_Comm comm, int comm_keyval, void *attribute_val, int *flag)
   ;
int PMPI_Comm_set_attr(PMPI_Comm comm, int comm_keyval, void *attribute_val);
int PMPI_Keyval_create(PMPI_Copy_function *copy_fn, PMPI_Delete_function *delete_fn, int *keyval,
                       void *extra_state);
int PMPI_Keyval_free(int *keyval);
int PMPI_Type_create_keyval(PMPI_Type_copy_attr_function *type_copy_attr_fn,
                            PMPI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval,
                            void *extra_state);
int PMPI_Type_delete_attr(PMPI_Datatype datatype, int type_keyval);
int PMPI_Type_free_keyval(int *type_keyval);
int PMPI_Type_get_attr(PMPI_Datatype datatype, int type_keyval, void *attribute_val, int *flag)
   ;
int PMPI_Type_set_attr(PMPI_Datatype datatype, int type_keyval, void *attribute_val)
   ;
int PMPI_Win_create_keyval(PMPI_Win_copy_attr_function *win_copy_attr_fn,
                           PMPI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval,
                           void *extra_state);
int PMPI_Win_delete_attr(PMPI_Win win, int win_keyval);
int PMPI_Win_free_keyval(int *win_keyval);
int PMPI_Win_get_attr(PMPI_Win win, int win_keyval, void *attribute_val, int *flag)
   ;
int PMPI_Win_set_attr(PMPI_Win win, int win_keyval, void *attribute_val);
int PMPI_Allgather(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                   int recvcount, PMPI_Datatype recvtype, PMPI_Comm comm)
                   ;
int PMPI_Allgather_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype, void *recvbuf,
                     PMPI_Count recvcount, PMPI_Datatype recvtype, PMPI_Comm comm)
                     ;
int PMPI_Allgather_init(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                        int recvcount, PMPI_Datatype recvtype, PMPI_Comm comm, PMPI_Info info,
                        PMPI_Request *request)
                        ;
int PMPI_Allgather_init_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                          void *recvbuf, PMPI_Count recvcount, PMPI_Datatype recvtype, PMPI_Comm comm,
                          PMPI_Info info, PMPI_Request *request)
                          ;
int PMPI_Allgatherv(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                    const int recvcounts[], const int displs[], PMPI_Datatype recvtype,
                    PMPI_Comm comm)
                    ;
int PMPI_Allgatherv_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                      void *recvbuf, const PMPI_Count recvcounts[], const PMPI_Aint displs[],
                      PMPI_Datatype recvtype, PMPI_Comm comm)
                      ;
int PMPI_Allgatherv_init(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                         const int recvcounts[], const int displs[], PMPI_Datatype recvtype,
                         PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                         ;
int PMPI_Allgatherv_init_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                           void *recvbuf, const PMPI_Count recvcounts[], const PMPI_Aint displs[],
                           PMPI_Datatype recvtype, PMPI_Comm comm, PMPI_Info info,
                           PMPI_Request *request)
                           ;
int PMPI_Allreduce(const void *sendbuf, void *recvbuf, int count, PMPI_Datatype datatype, PMPI_Op op,
                   PMPI_Comm comm)
                   ;
int PMPI_Allreduce_c(const void *sendbuf, void *recvbuf, PMPI_Count count, PMPI_Datatype datatype,
                     PMPI_Op op, PMPI_Comm comm)
                     ;
int PMPI_Allreduce_init(const void *sendbuf, void *recvbuf, int count, PMPI_Datatype datatype,
                        PMPI_Op op, PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                        ;
int PMPI_Allreduce_init_c(const void *sendbuf, void *recvbuf, PMPI_Count count,
                          PMPI_Datatype datatype, PMPI_Op op, PMPI_Comm comm, PMPI_Info info,
                          PMPI_Request *request)
                          ;
int PMPI_Alltoall(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                  int recvcount, PMPI_Datatype recvtype, PMPI_Comm comm)
                  ;
int PMPI_Alltoall_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype, void *recvbuf,
                    PMPI_Count recvcount, PMPI_Datatype recvtype, PMPI_Comm comm)
                    ;
int PMPI_Alltoall_init(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                       int recvcount, PMPI_Datatype recvtype, PMPI_Comm comm, PMPI_Info info,
                       PMPI_Request *request)
                       ;
int PMPI_Alltoall_init_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                         void *recvbuf, PMPI_Count recvcount, PMPI_Datatype recvtype, PMPI_Comm comm,
                         PMPI_Info info, PMPI_Request *request)
                         ;
int PMPI_Alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[],
                   PMPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                   const int rdispls[], PMPI_Datatype recvtype, PMPI_Comm comm)
                   ;
int PMPI_Alltoallv_c(const void *sendbuf, const PMPI_Count sendcounts[], const PMPI_Aint sdispls[],
                     PMPI_Datatype sendtype, void *recvbuf, const PMPI_Count recvcounts[],
                     const PMPI_Aint rdispls[], PMPI_Datatype recvtype, PMPI_Comm comm)
                     ;
int PMPI_Alltoallv_init(const void *sendbuf, const int sendcounts[], const int sdispls[],
                        PMPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                        const int rdispls[], PMPI_Datatype recvtype, PMPI_Comm comm, PMPI_Info info,
                        PMPI_Request *request)
                        ;
int PMPI_Alltoallv_init_c(const void *sendbuf, const PMPI_Count sendcounts[],
                          const PMPI_Aint sdispls[], PMPI_Datatype sendtype, void *recvbuf,
                          const PMPI_Count recvcounts[], const PMPI_Aint rdispls[],
                          PMPI_Datatype recvtype, PMPI_Comm comm, PMPI_Info info,
                          PMPI_Request *request)
                          ;
int PMPI_Alltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[],
                   const PMPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
                   const int rdispls[], const PMPI_Datatype recvtypes[], PMPI_Comm comm)
                  ;
int PMPI_Alltoallw_c(const void *sendbuf, const PMPI_Count sendcounts[], const PMPI_Aint sdispls[],
                     const PMPI_Datatype sendtypes[], void *recvbuf, const PMPI_Count recvcounts[],
                     const PMPI_Aint rdispls[], const PMPI_Datatype recvtypes[], PMPI_Comm comm)
                    ;
int PMPI_Alltoallw_init(const void *sendbuf, const int sendcounts[], const int sdispls[],
                        const PMPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
                        const int rdispls[], const PMPI_Datatype recvtypes[], PMPI_Comm comm,
                        PMPI_Info info, PMPI_Request *request);
int PMPI_Alltoallw_init_c(const void *sendbuf, const PMPI_Count sendcounts[],
                          const PMPI_Aint sdispls[], const PMPI_Datatype sendtypes[], void *recvbuf,
                          const PMPI_Count recvcounts[], const PMPI_Aint rdispls[],
                          const PMPI_Datatype recvtypes[], PMPI_Comm comm, PMPI_Info info,
                          PMPI_Request *request);
int PMPI_Barrier(PMPI_Comm comm);
int PMPI_Barrier_init(PMPI_Comm comm, PMPI_Info info, PMPI_Request *request);
int PMPI_Bcast(void *buffer, int count, PMPI_Datatype datatype, int root, PMPI_Comm comm)
    ;
int PMPI_Bcast_c(void *buffer, PMPI_Count count, PMPI_Datatype datatype, int root, PMPI_Comm comm)
    ;
int PMPI_Bcast_init(void *buffer, int count, PMPI_Datatype datatype, int root, PMPI_Comm comm,
                    PMPI_Info info, PMPI_Request *request)
                    ;
int PMPI_Bcast_init_c(void *buffer, PMPI_Count count, PMPI_Datatype datatype, int root, PMPI_Comm comm,
                      PMPI_Info info, PMPI_Request *request)
                      ;
int PMPI_Exscan(const void *sendbuf, void *recvbuf, int count, PMPI_Datatype datatype, PMPI_Op op,
                PMPI_Comm comm)
                ;
int PMPI_Exscan_c(const void *sendbuf, void *recvbuf, PMPI_Count count, PMPI_Datatype datatype,
                  PMPI_Op op, PMPI_Comm comm)
                  ;
int PMPI_Exscan_init(const void *sendbuf, void *recvbuf, int count, PMPI_Datatype datatype,
                     PMPI_Op op, PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                     ;
int PMPI_Exscan_init_c(const void *sendbuf, void *recvbuf, PMPI_Count count, PMPI_Datatype datatype,
                       PMPI_Op op, PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                       ;
int PMPI_Gather(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                int recvcount, PMPI_Datatype recvtype, int root, PMPI_Comm comm)
                ;
int PMPI_Gather_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype, void *recvbuf,
                  PMPI_Count recvcount, PMPI_Datatype recvtype, int root, PMPI_Comm comm)
                  ;
int PMPI_Gather_init(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                     int recvcount, PMPI_Datatype recvtype, int root, PMPI_Comm comm, PMPI_Info info,
                     PMPI_Request *request)
                     ;
int PMPI_Gather_init_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                       void *recvbuf, PMPI_Count recvcount, PMPI_Datatype recvtype, int root,
                       PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                       ;
int PMPI_Gatherv(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                 const int recvcounts[], const int displs[], PMPI_Datatype recvtype, int root,
                 PMPI_Comm comm)
                 ;
int PMPI_Gatherv_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype, void *recvbuf,
                   const PMPI_Count recvcounts[], const PMPI_Aint displs[], PMPI_Datatype recvtype,
                   int root, PMPI_Comm comm)
                   ;
int PMPI_Gatherv_init(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                      const int recvcounts[], const int displs[], PMPI_Datatype recvtype, int root,
                      PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                      ;
int PMPI_Gatherv_init_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                        void *recvbuf, const PMPI_Count recvcounts[], const PMPI_Aint displs[],
                        PMPI_Datatype recvtype, int root, PMPI_Comm comm, PMPI_Info info,
                        PMPI_Request *request)
                        ;
int PMPI_Iallgather(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                    int recvcount, PMPI_Datatype recvtype, PMPI_Comm comm, PMPI_Request *request)
                    ;
int PMPI_Iallgather_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                      void *recvbuf, PMPI_Count recvcount, PMPI_Datatype recvtype, PMPI_Comm comm,
                      PMPI_Request *request)
                      ;
int PMPI_Iallgatherv(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                     const int recvcounts[], const int displs[], PMPI_Datatype recvtype,
                     PMPI_Comm comm, PMPI_Request *request)
                     ;
int PMPI_Iallgatherv_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                       void *recvbuf, const PMPI_Count recvcounts[], const PMPI_Aint displs[],
                       PMPI_Datatype recvtype, PMPI_Comm comm, PMPI_Request *request)
                       ;
int PMPI_Iallreduce(const void *sendbuf, void *recvbuf, int count, PMPI_Datatype datatype, PMPI_Op op,
                    PMPI_Comm comm, PMPI_Request *request)
                    ;
int PMPI_Iallreduce_c(const void *sendbuf, void *recvbuf, PMPI_Count count, PMPI_Datatype datatype,
                      PMPI_Op op, PMPI_Comm comm, PMPI_Request *request)
                      ;
int PMPI_Ialltoall(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                   int recvcount, PMPI_Datatype recvtype, PMPI_Comm comm, PMPI_Request *request)
                   ;
int PMPI_Ialltoall_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype, void *recvbuf,
                     PMPI_Count recvcount, PMPI_Datatype recvtype, PMPI_Comm comm,
                     PMPI_Request *request)
                     ;
int PMPI_Ialltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[],
                    PMPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                    const int rdispls[], PMPI_Datatype recvtype, PMPI_Comm comm,
                    PMPI_Request *request)
                    ;
int PMPI_Ialltoallv_c(const void *sendbuf, const PMPI_Count sendcounts[], const PMPI_Aint sdispls[],
                      PMPI_Datatype sendtype, void *recvbuf, const PMPI_Count recvcounts[],
                      const PMPI_Aint rdispls[], PMPI_Datatype recvtype, PMPI_Comm comm,
                      PMPI_Request *request)
                      ;
int PMPI_Ialltoallw(const void *sendbuf, const int sendcounts[], const int sdispls[],
                    const PMPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
                    const int rdispls[], const PMPI_Datatype recvtypes[], PMPI_Comm comm,
                    PMPI_Request *request);
int PMPI_Ialltoallw_c(const void *sendbuf, const PMPI_Count sendcounts[], const PMPI_Aint sdispls[],
                      const PMPI_Datatype sendtypes[], void *recvbuf, const PMPI_Count recvcounts[],
                      const PMPI_Aint rdispls[], const PMPI_Datatype recvtypes[], PMPI_Comm comm,
                      PMPI_Request *request);
int PMPI_Ibarrier(PMPI_Comm comm, PMPI_Request *request);
int PMPI_Ibcast(void *buffer, int count, PMPI_Datatype datatype, int root, PMPI_Comm comm,
                PMPI_Request *request) ;
int PMPI_Ibcast_c(void *buffer, PMPI_Count count, PMPI_Datatype datatype, int root, PMPI_Comm comm,
                  PMPI_Request *request) ;
int PMPI_Iexscan(const void *sendbuf, void *recvbuf, int count, PMPI_Datatype datatype, PMPI_Op op,
                 PMPI_Comm comm, PMPI_Request *request)
                 ;
int PMPI_Iexscan_c(const void *sendbuf, void *recvbuf, PMPI_Count count, PMPI_Datatype datatype,
                   PMPI_Op op, PMPI_Comm comm, PMPI_Request *request)
                   ;
int PMPI_Igather(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                 int recvcount, PMPI_Datatype recvtype, int root, PMPI_Comm comm,
                 PMPI_Request *request)
                 ;
int PMPI_Igather_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype, void *recvbuf,
                   PMPI_Count recvcount, PMPI_Datatype recvtype, int root, PMPI_Comm comm,
                   PMPI_Request *request)
                   ;
int PMPI_Igatherv(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                  const int recvcounts[], const int displs[], PMPI_Datatype recvtype, int root,
                  PMPI_Comm comm, PMPI_Request *request)
                  ;
int PMPI_Igatherv_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype, void *recvbuf,
                    const PMPI_Count recvcounts[], const PMPI_Aint displs[], PMPI_Datatype recvtype,
                    int root, PMPI_Comm comm, PMPI_Request *request)
                    ;
int PMPI_Ineighbor_allgather(const void *sendbuf, int sendcount, PMPI_Datatype sendtype,
                             void *recvbuf, int recvcount, PMPI_Datatype recvtype, PMPI_Comm comm,
                             PMPI_Request *request)
                             ;
int PMPI_Ineighbor_allgather_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                               void *recvbuf, PMPI_Count recvcount, PMPI_Datatype recvtype,
                               PMPI_Comm comm, PMPI_Request *request)
                               ;
int PMPI_Ineighbor_allgatherv(const void *sendbuf, int sendcount, PMPI_Datatype sendtype,
                              void *recvbuf, const int recvcounts[], const int displs[],
                              PMPI_Datatype recvtype, PMPI_Comm comm, PMPI_Request *request)
                              ;
int PMPI_Ineighbor_allgatherv_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                                void *recvbuf, const PMPI_Count recvcounts[],
                                const PMPI_Aint displs[], PMPI_Datatype recvtype, PMPI_Comm comm,
                                PMPI_Request *request)
                                ;
int PMPI_Ineighbor_alltoall(const void *sendbuf, int sendcount, PMPI_Datatype sendtype,
                            void *recvbuf, int recvcount, PMPI_Datatype recvtype, PMPI_Comm comm,
                            PMPI_Request *request)
                            ;
int PMPI_Ineighbor_alltoall_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                              void *recvbuf, PMPI_Count recvcount, PMPI_Datatype recvtype,
                              PMPI_Comm comm, PMPI_Request *request)
                              ;
int PMPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[],
                             PMPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                             const int rdispls[], PMPI_Datatype recvtype, PMPI_Comm comm,
                             PMPI_Request *request)
                             ;
int PMPI_Ineighbor_alltoallv_c(const void *sendbuf, const PMPI_Count sendcounts[],
                               const PMPI_Aint sdispls[], PMPI_Datatype sendtype, void *recvbuf,
                               const PMPI_Count recvcounts[], const PMPI_Aint rdispls[],
                               PMPI_Datatype recvtype, PMPI_Comm comm, PMPI_Request *request)
                               ;
int PMPI_Ineighbor_alltoallw(const void *sendbuf, const int sendcounts[], const PMPI_Aint sdispls[],
                             const PMPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
                             const PMPI_Aint rdispls[], const PMPI_Datatype recvtypes[],
                             PMPI_Comm comm, PMPI_Request *request);
int PMPI_Ineighbor_alltoallw_c(const void *sendbuf, const PMPI_Count sendcounts[],
                               const PMPI_Aint sdispls[], const PMPI_Datatype sendtypes[],
                               void *recvbuf, const PMPI_Count recvcounts[],
                               const PMPI_Aint rdispls[], const PMPI_Datatype recvtypes[],
                               PMPI_Comm comm, PMPI_Request *request);
int PMPI_Ireduce(const void *sendbuf, void *recvbuf, int count, PMPI_Datatype datatype, PMPI_Op op,
                 int root, PMPI_Comm comm, PMPI_Request *request)
                 ;
int PMPI_Ireduce_c(const void *sendbuf, void *recvbuf, PMPI_Count count, PMPI_Datatype datatype,
                   PMPI_Op op, int root, PMPI_Comm comm, PMPI_Request *request)
                   ;
int PMPI_Ireduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[],
                         PMPI_Datatype datatype, PMPI_Op op, PMPI_Comm comm, PMPI_Request *request)
                         ;
int PMPI_Ireduce_scatter_c(const void *sendbuf, void *recvbuf, const PMPI_Count recvcounts[],
                           PMPI_Datatype datatype, PMPI_Op op, PMPI_Comm comm, PMPI_Request *request)
                           ;
int PMPI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount,
                               PMPI_Datatype datatype, PMPI_Op op, PMPI_Comm comm,
                               PMPI_Request *request)
                               ;
int PMPI_Ireduce_scatter_block_c(const void *sendbuf, void *recvbuf, PMPI_Count recvcount,
                                 PMPI_Datatype datatype, PMPI_Op op, PMPI_Comm comm,
                                 PMPI_Request *request)
                                 ;
int PMPI_Iscan(const void *sendbuf, void *recvbuf, int count, PMPI_Datatype datatype, PMPI_Op op,
               PMPI_Comm comm, PMPI_Request *request)
               ;
int PMPI_Iscan_c(const void *sendbuf, void *recvbuf, PMPI_Count count, PMPI_Datatype datatype,
                 PMPI_Op op, PMPI_Comm comm, PMPI_Request *request)
                 ;
int PMPI_Iscatter(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                  int recvcount, PMPI_Datatype recvtype, int root, PMPI_Comm comm,
                  PMPI_Request *request)
                  ;
int PMPI_Iscatter_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype, void *recvbuf,
                    PMPI_Count recvcount, PMPI_Datatype recvtype, int root, PMPI_Comm comm,
                    PMPI_Request *request)
                    ;
int PMPI_Iscatterv(const void *sendbuf, const int sendcounts[], const int displs[],
                   PMPI_Datatype sendtype, void *recvbuf, int recvcount, PMPI_Datatype recvtype,
                   int root, PMPI_Comm comm, PMPI_Request *request)
                   ;
int PMPI_Iscatterv_c(const void *sendbuf, const PMPI_Count sendcounts[], const PMPI_Aint displs[],
                     PMPI_Datatype sendtype, void *recvbuf, PMPI_Count recvcount,
                     PMPI_Datatype recvtype, int root, PMPI_Comm comm, PMPI_Request *request)
                     ;
int PMPI_Neighbor_allgather(const void *sendbuf, int sendcount, PMPI_Datatype sendtype,
                            void *recvbuf, int recvcount, PMPI_Datatype recvtype, PMPI_Comm comm)
                            ;
int PMPI_Neighbor_allgather_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                              void *recvbuf, PMPI_Count recvcount, PMPI_Datatype recvtype,
                              PMPI_Comm comm)
                              ;
int PMPI_Neighbor_allgather_init(const void *sendbuf, int sendcount, PMPI_Datatype sendtype,
                                 void *recvbuf, int recvcount, PMPI_Datatype recvtype, PMPI_Comm comm,
                                 PMPI_Info info, PMPI_Request *request)
                                 ;
int PMPI_Neighbor_allgather_init_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                                   void *recvbuf, PMPI_Count recvcount, PMPI_Datatype recvtype,
                                   PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                                   ;
int PMPI_Neighbor_allgatherv(const void *sendbuf, int sendcount, PMPI_Datatype sendtype,
                             void *recvbuf, const int recvcounts[], const int displs[],
                             PMPI_Datatype recvtype, PMPI_Comm comm)
                             ;
int PMPI_Neighbor_allgatherv_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                               void *recvbuf, const PMPI_Count recvcounts[], const PMPI_Aint displs[],
                               PMPI_Datatype recvtype, PMPI_Comm comm)
                               ;
int PMPI_Neighbor_allgatherv_init(const void *sendbuf, int sendcount, PMPI_Datatype sendtype,
                                  void *recvbuf, const int recvcounts[], const int displs[],
                                  PMPI_Datatype recvtype, PMPI_Comm comm, PMPI_Info info,
                                  PMPI_Request *request)
                                  ;
int PMPI_Neighbor_allgatherv_init_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                                    void *recvbuf, const PMPI_Count recvcounts[],
                                    const PMPI_Aint displs[], PMPI_Datatype recvtype, PMPI_Comm comm,
                                    PMPI_Info info, PMPI_Request *request)
                                    ;
int PMPI_Neighbor_alltoall(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                           int recvcount, PMPI_Datatype recvtype, PMPI_Comm comm)
                           ;
int PMPI_Neighbor_alltoall_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                             void *recvbuf, PMPI_Count recvcount, PMPI_Datatype recvtype,
                             PMPI_Comm comm)
                             ;
int PMPI_Neighbor_alltoall_init(const void *sendbuf, int sendcount, PMPI_Datatype sendtype,
                                void *recvbuf, int recvcount, PMPI_Datatype recvtype, PMPI_Comm comm,
                                PMPI_Info info, PMPI_Request *request)
                                ;
int PMPI_Neighbor_alltoall_init_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                                  void *recvbuf, PMPI_Count recvcount, PMPI_Datatype recvtype,
                                  PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                                  ;
int PMPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[],
                            PMPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                            const int rdispls[], PMPI_Datatype recvtype, PMPI_Comm comm)
                            ;
int PMPI_Neighbor_alltoallv_c(const void *sendbuf, const PMPI_Count sendcounts[],
                              const PMPI_Aint sdispls[], PMPI_Datatype sendtype, void *recvbuf,
                              const PMPI_Count recvcounts[], const PMPI_Aint rdispls[],
                              PMPI_Datatype recvtype, PMPI_Comm comm)
                              ;
int PMPI_Neighbor_alltoallv_init(const void *sendbuf, const int sendcounts[], const int sdispls[],
                                 PMPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                                 const int rdispls[], PMPI_Datatype recvtype, PMPI_Comm comm,
                                 PMPI_Info info, PMPI_Request *request)
                                 ;
int PMPI_Neighbor_alltoallv_init_c(const void *sendbuf, const PMPI_Count sendcounts[],
                                   const PMPI_Aint sdispls[], PMPI_Datatype sendtype, void *recvbuf,
                                   const PMPI_Count recvcounts[], const PMPI_Aint rdispls[],
                                   PMPI_Datatype recvtype, PMPI_Comm comm, PMPI_Info info,
                                   PMPI_Request *request)
                                   ;
int PMPI_Neighbor_alltoallw(const void *sendbuf, const int sendcounts[], const PMPI_Aint sdispls[],
                            const PMPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
                            const PMPI_Aint rdispls[], const PMPI_Datatype recvtypes[],
                            PMPI_Comm comm);
int PMPI_Neighbor_alltoallw_c(const void *sendbuf, const PMPI_Count sendcounts[],
                              const PMPI_Aint sdispls[], const PMPI_Datatype sendtypes[],
                              void *recvbuf, const PMPI_Count recvcounts[], const PMPI_Aint rdispls[],
                              const PMPI_Datatype recvtypes[], PMPI_Comm comm);
int PMPI_Neighbor_alltoallw_init(const void *sendbuf, const int sendcounts[],
                                 const PMPI_Aint sdispls[], const PMPI_Datatype sendtypes[],
                                 void *recvbuf, const int recvcounts[], const PMPI_Aint rdispls[],
                                 const PMPI_Datatype recvtypes[], PMPI_Comm comm, PMPI_Info info,
                                 PMPI_Request *request);
int PMPI_Neighbor_alltoallw_init_c(const void *sendbuf, const PMPI_Count sendcounts[],
                                   const PMPI_Aint sdispls[], const PMPI_Datatype sendtypes[],
                                   void *recvbuf, const PMPI_Count recvcounts[],
                                   const PMPI_Aint rdispls[], const PMPI_Datatype recvtypes[],
                                   PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                                  ;
int PMPI_Reduce(const void *sendbuf, void *recvbuf, int count, PMPI_Datatype datatype, PMPI_Op op,
                int root, PMPI_Comm comm)
                ;
int PMPI_Reduce_c(const void *sendbuf, void *recvbuf, PMPI_Count count, PMPI_Datatype datatype,
                  PMPI_Op op, int root, PMPI_Comm comm)
                  ;
int PMPI_Reduce_init(const void *sendbuf, void *recvbuf, int count, PMPI_Datatype datatype,
                     PMPI_Op op, int root, PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                     ;
int PMPI_Reduce_init_c(const void *sendbuf, void *recvbuf, PMPI_Count count, PMPI_Datatype datatype,
                       PMPI_Op op, int root, PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                       ;
int PMPI_Reduce_local(const void *inbuf, void *inoutbuf, int count, PMPI_Datatype datatype,
                      PMPI_Op op)
                      ;
int PMPI_Reduce_local_c(const void *inbuf, void *inoutbuf, PMPI_Count count, PMPI_Datatype datatype,
                        PMPI_Op op)
                        ;
int PMPI_Reduce_scatter(const void *sendbuf, void *recvbuf, const int recvcounts[],
                        PMPI_Datatype datatype, PMPI_Op op, PMPI_Comm comm)
                        ;
int PMPI_Reduce_scatter_c(const void *sendbuf, void *recvbuf, const PMPI_Count recvcounts[],
                          PMPI_Datatype datatype, PMPI_Op op, PMPI_Comm comm)
                          ;
int PMPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf, int recvcount,
                              PMPI_Datatype datatype, PMPI_Op op, PMPI_Comm comm)
                              ;
int PMPI_Reduce_scatter_block_c(const void *sendbuf, void *recvbuf, PMPI_Count recvcount,
                                PMPI_Datatype datatype, PMPI_Op op, PMPI_Comm comm)
                                ;
int PMPI_Reduce_scatter_block_init(const void *sendbuf, void *recvbuf, int recvcount,
                                   PMPI_Datatype datatype, PMPI_Op op, PMPI_Comm comm, PMPI_Info info,
                                   PMPI_Request *request)
                                   ;
int PMPI_Reduce_scatter_block_init_c(const void *sendbuf, void *recvbuf, PMPI_Count recvcount,
                                     PMPI_Datatype datatype, PMPI_Op op, PMPI_Comm comm, PMPI_Info info,
                                     PMPI_Request *request)
                                     ;
int PMPI_Reduce_scatter_init(const void *sendbuf, void *recvbuf, const int recvcounts[],
                             PMPI_Datatype datatype, PMPI_Op op, PMPI_Comm comm, PMPI_Info info,
                             PMPI_Request *request)
                             ;
int PMPI_Reduce_scatter_init_c(const void *sendbuf, void *recvbuf, const PMPI_Count recvcounts[],
                               PMPI_Datatype datatype, PMPI_Op op, PMPI_Comm comm, PMPI_Info info,
                               PMPI_Request *request)
                               ;
int PMPI_Scan(const void *sendbuf, void *recvbuf, int count, PMPI_Datatype datatype, PMPI_Op op,
              PMPI_Comm comm)
              ;
int PMPI_Scan_c(const void *sendbuf, void *recvbuf, PMPI_Count count, PMPI_Datatype datatype,
                PMPI_Op op, PMPI_Comm comm)
                ;
int PMPI_Scan_init(const void *sendbuf, void *recvbuf, int count, PMPI_Datatype datatype, PMPI_Op op,
                   PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                   ;
int PMPI_Scan_init_c(const void *sendbuf, void *recvbuf, PMPI_Count count, PMPI_Datatype datatype,
                     PMPI_Op op, PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                     ;
int PMPI_Scatter(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                 int recvcount, PMPI_Datatype recvtype, int root, PMPI_Comm comm)
                 ;
int PMPI_Scatter_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype, void *recvbuf,
                   PMPI_Count recvcount, PMPI_Datatype recvtype, int root, PMPI_Comm comm)
                   ;
int PMPI_Scatter_init(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, void *recvbuf,
                      int recvcount, PMPI_Datatype recvtype, int root, PMPI_Comm comm, PMPI_Info info,
                      PMPI_Request *request)
                      ;
int PMPI_Scatter_init_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype,
                        void *recvbuf, PMPI_Count recvcount, PMPI_Datatype recvtype, int root,
                        PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                        ;
int PMPI_Scatterv(const void *sendbuf, const int sendcounts[], const int displs[],
                  PMPI_Datatype sendtype, void *recvbuf, int recvcount, PMPI_Datatype recvtype,
                  int root, PMPI_Comm comm)
                  ;
int PMPI_Scatterv_c(const void *sendbuf, const PMPI_Count sendcounts[], const PMPI_Aint displs[],
                    PMPI_Datatype sendtype, void *recvbuf, PMPI_Count recvcount,
                    PMPI_Datatype recvtype, int root, PMPI_Comm comm)
                    ;
int PMPI_Scatterv_init(const void *sendbuf, const int sendcounts[], const int displs[],
                       PMPI_Datatype sendtype, void *recvbuf, int recvcount, PMPI_Datatype recvtype,
                       int root, PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                       ;
int PMPI_Scatterv_init_c(const void *sendbuf, const PMPI_Count sendcounts[], const PMPI_Aint displs[],
                         PMPI_Datatype sendtype, void *recvbuf, PMPI_Count recvcount,
                         PMPI_Datatype recvtype, int root, PMPI_Comm comm, PMPI_Info info,
                         PMPI_Request *request)
                         ;
int PMPI_Comm_compare(PMPI_Comm comm1, PMPI_Comm comm2, int *result);
int PMPI_Comm_create(PMPI_Comm comm, PMPI_Group group, PMPI_Comm *newcomm);
int PMPI_Comm_create_group(PMPI_Comm comm, PMPI_Group group, int tag, PMPI_Comm *newcomm)
   ;
int PMPI_Comm_dup(PMPI_Comm comm, PMPI_Comm *newcomm);
int PMPI_Comm_dup_with_info(PMPI_Comm comm, PMPI_Info info, PMPI_Comm *newcomm);
int PMPI_Comm_free(PMPI_Comm *comm);
int PMPI_Comm_get_info(PMPI_Comm comm, PMPI_Info *info_used);
int PMPI_Comm_get_name(PMPI_Comm comm, char *comm_name, int *resultlen);
int PMPI_Comm_group(PMPI_Comm comm, PMPI_Group *group);
int PMPI_Comm_idup(PMPI_Comm comm, PMPI_Comm *newcomm, PMPI_Request *request);
int PMPI_Comm_idup_with_info(PMPI_Comm comm, PMPI_Info info, PMPI_Comm *newcomm, PMPI_Request *request)
   ;
int PMPI_Comm_rank(PMPI_Comm comm, int *rank);
int PMPI_Comm_remote_group(PMPI_Comm comm, PMPI_Group *group);
int PMPI_Comm_remote_size(PMPI_Comm comm, int *size);
int PMPI_Comm_set_info(PMPI_Comm comm, PMPI_Info info);
int PMPI_Comm_set_name(PMPI_Comm comm, const char *comm_name);
int PMPI_Comm_size(PMPI_Comm comm, int *size);
int PMPI_Comm_split(PMPI_Comm comm, int color, int key, PMPI_Comm *newcomm);
int PMPI_Comm_split_type(PMPI_Comm comm, int split_type, int key, PMPI_Info info, PMPI_Comm *newcomm)
   ;
int PMPI_Comm_test_inter(PMPI_Comm comm, int *flag);
int PMPI_Intercomm_create(PMPI_Comm local_comm, int local_leader, PMPI_Comm peer_comm,
                          int remote_leader, int tag, PMPI_Comm *newintercomm);
int PMPI_Intercomm_create_from_groups(PMPI_Group local_group, int local_leader,
                                      PMPI_Group remote_group, int remote_leader,
                                      const char *stringtag, PMPI_Info info,
                                      PMPI_Errhandler errhandler, PMPI_Comm *newintercomm)
                                     ;
int PMPI_Intercomm_merge(PMPI_Comm intercomm, int high, PMPI_Comm *newintracomm);
int PMPIX_Comm_revoke(PMPI_Comm comm);
int PMPIX_Comm_shrink(PMPI_Comm comm, PMPI_Comm *newcomm);
int PMPIX_Comm_failure_ack(PMPI_Comm comm);
int PMPIX_Comm_failure_get_acked(PMPI_Comm comm, PMPI_Group *failedgrp);
int PMPIX_Comm_agree(PMPI_Comm comm, int *flag);
int PMPIX_Comm_get_failed(PMPI_Comm comm, PMPI_Group *failedgrp);
int PMPI_Get_address(const void *location, PMPI_Aint *address);
int PMPI_Get_count(const PMPI_Status *status, PMPI_Datatype datatype, int *count);
int PMPI_Get_count_c(const PMPI_Status *status, PMPI_Datatype datatype, PMPI_Count *count)
   ;
int PMPI_Get_elements(const PMPI_Status *status, PMPI_Datatype datatype, int *count)
   ;
int PMPI_Get_elements_c(const PMPI_Status *status, PMPI_Datatype datatype, PMPI_Count *count)
   ;
int PMPI_Get_elements_x(const PMPI_Status *status, PMPI_Datatype datatype, PMPI_Count *count)
   ;
int PMPI_Pack(const void *inbuf, int incount, PMPI_Datatype datatype, void *outbuf, int outsize,
              int *position, PMPI_Comm comm);
int PMPI_Pack_c(const void *inbuf, PMPI_Count incount, PMPI_Datatype datatype, void *outbuf,
                PMPI_Count outsize, PMPI_Count *position, PMPI_Comm comm);
int PMPI_Pack_external(const char *datarep, const void *inbuf, int incount, PMPI_Datatype datatype,
                       void *outbuf, PMPI_Aint outsize, PMPI_Aint *position);
int PMPI_Pack_external_c(const char *datarep, const void *inbuf, PMPI_Count incount,
                         PMPI_Datatype datatype, void *outbuf, PMPI_Count outsize,
                         PMPI_Count *position);
int PMPI_Pack_external_size(const char *datarep, int incount, PMPI_Datatype datatype,
                            PMPI_Aint *size);
int PMPI_Pack_external_size_c(const char *datarep, PMPI_Count incount, PMPI_Datatype datatype,
                              PMPI_Count *size);
int PMPI_Pack_size(int incount, PMPI_Datatype datatype, PMPI_Comm comm, int *size);
int PMPI_Pack_size_c(PMPI_Count incount, PMPI_Datatype datatype, PMPI_Comm comm, PMPI_Count *size)
   ;
int PMPI_Status_set_elements(PMPI_Status *status, PMPI_Datatype datatype, int count)
   ;
int PMPI_Status_set_elements_c(PMPI_Status *status, PMPI_Datatype datatype, PMPI_Count count)
   ;
int PMPI_Status_set_elements_x(PMPI_Status *status, PMPI_Datatype datatype, PMPI_Count count)
   ;
int PMPI_Type_commit(PMPI_Datatype *datatype);
int PMPI_Type_contiguous(int count, PMPI_Datatype oldtype, PMPI_Datatype *newtype);
int PMPI_Type_contiguous_c(PMPI_Count count, PMPI_Datatype oldtype, PMPI_Datatype *newtype)
   ;
int PMPI_Type_create_darray(int size, int rank, int ndims, const int array_of_gsizes[],
                            const int array_of_distribs[], const int array_of_dargs[],
                            const int array_of_psizes[], int order, PMPI_Datatype oldtype,
                            PMPI_Datatype *newtype);
int PMPI_Type_create_darray_c(int size, int rank, int ndims, const PMPI_Count array_of_gsizes[],
                              const int array_of_distribs[], const int array_of_dargs[],
                              const int array_of_psizes[], int order, PMPI_Datatype oldtype,
                              PMPI_Datatype *newtype);
int PMPI_Type_create_hindexed(int count, const int array_of_blocklengths[],
                              const PMPI_Aint array_of_displacements[], PMPI_Datatype oldtype,
                              PMPI_Datatype *newtype);
int PMPI_Type_create_hindexed_c(PMPI_Count count, const PMPI_Count array_of_blocklengths[],
                                const PMPI_Count array_of_displacements[], PMPI_Datatype oldtype,
                                PMPI_Datatype *newtype);
int PMPI_Type_create_hindexed_block(int count, int blocklength,
                                    const PMPI_Aint array_of_displacements[], PMPI_Datatype oldtype,
                                    PMPI_Datatype *newtype);
int PMPI_Type_create_hindexed_block_c(PMPI_Count count, PMPI_Count blocklength,
                                      const PMPI_Count array_of_displacements[],
                                      PMPI_Datatype oldtype, PMPI_Datatype *newtype)
                                     ;
int PMPI_Type_create_hvector(int count, int blocklength, PMPI_Aint stride, PMPI_Datatype oldtype,
                             PMPI_Datatype *newtype);
int PMPI_Type_create_hvector_c(PMPI_Count count, PMPI_Count blocklength, PMPI_Count stride,
                               PMPI_Datatype oldtype, PMPI_Datatype *newtype);
int PMPI_Type_create_indexed_block(int count, int blocklength, const int array_of_displacements[],
                                   PMPI_Datatype oldtype, PMPI_Datatype *newtype);
int PMPI_Type_create_indexed_block_c(PMPI_Count count, PMPI_Count blocklength,
                                     const PMPI_Count array_of_displacements[], PMPI_Datatype oldtype,
                                     PMPI_Datatype *newtype);
int PMPI_Type_create_resized(PMPI_Datatype oldtype, PMPI_Aint lb, PMPI_Aint extent,
                             PMPI_Datatype *newtype);
int PMPI_Type_create_resized_c(PMPI_Datatype oldtype, PMPI_Count lb, PMPI_Count extent,
                               PMPI_Datatype *newtype);
int PMPI_Type_create_struct(int count, const int array_of_blocklengths[],
                            const PMPI_Aint array_of_displacements[],
                            const PMPI_Datatype array_of_types[], PMPI_Datatype *newtype)
                           ;
int PMPI_Type_create_struct_c(PMPI_Count count, const PMPI_Count array_of_blocklengths[],
                              const PMPI_Count array_of_displacements[],
                              const PMPI_Datatype array_of_types[], PMPI_Datatype *newtype)
                             ;
int PMPI_Type_create_subarray(int ndims, const int array_of_sizes[], const int array_of_subsizes[],
                              const int array_of_starts[], int order, PMPI_Datatype oldtype,
                              PMPI_Datatype *newtype);
int PMPI_Type_create_subarray_c(int ndims, const PMPI_Count array_of_sizes[],
                                const PMPI_Count array_of_subsizes[],
                                const PMPI_Count array_of_starts[], int order, PMPI_Datatype oldtype,
                                PMPI_Datatype *newtype);
int PMPI_Type_dup(PMPI_Datatype oldtype, PMPI_Datatype *newtype);
int PMPI_Type_free(PMPI_Datatype *datatype);
int PMPI_Type_get_contents(PMPI_Datatype datatype, int max_integers, int max_addresses,
                           int max_datatypes, int array_of_integers[],
                           PMPI_Aint array_of_addresses[], PMPI_Datatype array_of_datatypes[])
                          ;
int PMPI_Type_get_contents_c(PMPI_Datatype datatype, PMPI_Count max_integers, PMPI_Count max_addresses,
                             PMPI_Count max_large_counts, PMPI_Count max_datatypes,
                             int array_of_integers[], PMPI_Aint array_of_addresses[],
                             PMPI_Count array_of_large_counts[], PMPI_Datatype array_of_datatypes[])
                            ;
int PMPI_Type_get_envelope(PMPI_Datatype datatype, int *num_integers, int *num_addresses,
                           int *num_datatypes, int *combiner);
int PMPI_Type_get_envelope_c(PMPI_Datatype datatype, PMPI_Count *num_integers,
                             PMPI_Count *num_addresses, PMPI_Count *num_large_counts,
                             PMPI_Count *num_datatypes, int *combiner);
int PMPI_Type_get_extent(PMPI_Datatype datatype, PMPI_Aint *lb, PMPI_Aint *extent);
int PMPI_Type_get_extent_c(PMPI_Datatype datatype, PMPI_Count *lb, PMPI_Count *extent)
   ;
int PMPI_Type_get_extent_x(PMPI_Datatype datatype, PMPI_Count *lb, PMPI_Count *extent)
   ;
int PMPI_Type_get_name(PMPI_Datatype datatype, char *type_name, int *resultlen);
int PMPI_Type_get_true_extent(PMPI_Datatype datatype, PMPI_Aint *true_lb, PMPI_Aint *true_extent)
   ;
int PMPI_Type_get_true_extent_c(PMPI_Datatype datatype, PMPI_Count *true_lb, PMPI_Count *true_extent)
   ;
int PMPI_Type_get_true_extent_x(PMPI_Datatype datatype, PMPI_Count *true_lb, PMPI_Count *true_extent)
   ;
int PMPI_Type_indexed(int count, const int array_of_blocklengths[],
                      const int array_of_displacements[], PMPI_Datatype oldtype,
                      PMPI_Datatype *newtype);
int PMPI_Type_indexed_c(PMPI_Count count, const PMPI_Count array_of_blocklengths[],
                        const PMPI_Count array_of_displacements[], PMPI_Datatype oldtype,
                        PMPI_Datatype *newtype);
int PMPI_Type_match_size(int typeclass, int size, PMPI_Datatype *datatype);
int PMPI_Type_set_name(PMPI_Datatype datatype, const char *type_name);
int PMPI_Type_size(PMPI_Datatype datatype, int *size);
int PMPI_Type_size_c(PMPI_Datatype datatype, PMPI_Count *size);
int PMPI_Type_size_x(PMPI_Datatype datatype, PMPI_Count *size);
int PMPI_Type_vector(int count, int blocklength, int stride, PMPI_Datatype oldtype,
                     PMPI_Datatype *newtype);
int PMPI_Type_vector_c(PMPI_Count count, PMPI_Count blocklength, PMPI_Count stride,
                       PMPI_Datatype oldtype, PMPI_Datatype *newtype);
int PMPI_Unpack(const void *inbuf, int insize, int *position, void *outbuf, int outcount,
                PMPI_Datatype datatype, PMPI_Comm comm);
int PMPI_Unpack_c(const void *inbuf, PMPI_Count insize, PMPI_Count *position, void *outbuf,
                  PMPI_Count outcount, PMPI_Datatype datatype, PMPI_Comm comm);
int PMPI_Unpack_external(const char datarep[], const void *inbuf, PMPI_Aint insize,
                         PMPI_Aint *position, void *outbuf, int outcount, PMPI_Datatype datatype)
                        ;
int PMPI_Unpack_external_c(const char datarep[], const void *inbuf, PMPI_Count insize,
                           PMPI_Count *position, void *outbuf, PMPI_Count outcount,
                           PMPI_Datatype datatype);
int PMPI_Address(void *location, PMPI_Aint *address);
int PMPI_Type_extent(PMPI_Datatype datatype, PMPI_Aint *extent);
int PMPI_Type_lb(PMPI_Datatype datatype, PMPI_Aint *displacement);
int PMPI_Type_ub(PMPI_Datatype datatype, PMPI_Aint *displacement);
int PMPI_Type_hindexed(int count, int array_of_blocklengths[], PMPI_Aint array_of_displacements[],
                       PMPI_Datatype oldtype, PMPI_Datatype *newtype);
int PMPI_Type_hvector(int count, int blocklength, PMPI_Aint stride, PMPI_Datatype oldtype,
                      PMPI_Datatype *newtype);
int PMPI_Type_struct(int count, int array_of_blocklengths[], PMPI_Aint array_of_displacements[],
                     PMPI_Datatype array_of_types[], PMPI_Datatype *newtype);
int PMPIX_Type_iov_len(PMPI_Datatype datatype, PMPI_Count max_iov_bytes, PMPI_Count *iov_len,
                       PMPI_Count *actual_iov_bytes);
int PMPIX_Type_iov(PMPI_Datatype datatype, PMPI_Count iov_offset, PMPIX_Iov *iov,
                   PMPI_Count max_iov_len, PMPI_Count *actual_iov_len);
int PMPI_Add_error_class(int *errorclass);
int PMPI_Add_error_code(int errorclass, int *errorcode);
int PMPI_Add_error_string(int errorcode, const char *string);
int PMPI_Comm_call_errhandler(PMPI_Comm comm, int errorcode);
int PMPI_Comm_create_errhandler(PMPI_Comm_errhandler_function *comm_errhandler_fn,
                                PMPI_Errhandler *errhandler);
int PMPI_Comm_get_errhandler(PMPI_Comm comm, PMPI_Errhandler *errhandler);
int PMPI_Comm_set_errhandler(PMPI_Comm comm, PMPI_Errhandler errhandler);
int PMPI_Errhandler_free(PMPI_Errhandler *errhandler);
int PMPI_Error_class(int errorcode, int *errorclass);
int PMPI_Error_string(int errorcode, char *string, int *resultlen);
int PMPI_File_call_errhandler(PMPI_File fh, int errorcode);
int PMPI_File_create_errhandler(PMPI_File_errhandler_function *file_errhandler_fn,
                                PMPI_Errhandler *errhandler);
int PMPI_File_get_errhandler(PMPI_File file, PMPI_Errhandler *errhandler);
int PMPI_File_set_errhandler(PMPI_File file, PMPI_Errhandler errhandler);
int PMPI_Session_call_errhandler(PMPI_Session session, int errorcode);
int PMPI_Session_create_errhandler(PMPI_Session_errhandler_function *session_errhandler_fn,
                                   PMPI_Errhandler *errhandler);
int PMPI_Session_get_errhandler(PMPI_Session session, PMPI_Errhandler *errhandler);
int PMPI_Session_set_errhandler(PMPI_Session session, PMPI_Errhandler errhandler);
int PMPI_Win_call_errhandler(PMPI_Win win, int errorcode);
int PMPI_Win_create_errhandler(PMPI_Win_errhandler_function *win_errhandler_fn,
                               PMPI_Errhandler *errhandler);
int PMPI_Win_get_errhandler(PMPI_Win win, PMPI_Errhandler *errhandler);
int PMPI_Win_set_errhandler(PMPI_Win win, PMPI_Errhandler errhandler);
int PMPIX_Delete_error_class(int errorclass);
int PMPIX_Delete_error_code(int errorcode);
int PMPIX_Delete_error_string(int errorcode);
int PMPI_Errhandler_create(PMPI_Comm_errhandler_function *comm_errhandler_fn,
                           PMPI_Errhandler *errhandler);
int PMPI_Errhandler_get(PMPI_Comm comm, PMPI_Errhandler *errhandler);
int PMPI_Errhandler_set(PMPI_Comm comm, PMPI_Errhandler errhandler);
int PMPI_Group_compare(PMPI_Group group1, PMPI_Group group2, int *result);
int PMPI_Group_difference(PMPI_Group group1, PMPI_Group group2, PMPI_Group *newgroup)
   ;
int PMPI_Group_excl(PMPI_Group group, int n, const int ranks[], PMPI_Group *newgroup)
   ;
int PMPI_Group_free(PMPI_Group *group);
int PMPI_Group_incl(PMPI_Group group, int n, const int ranks[], PMPI_Group *newgroup)
   ;
int PMPI_Group_intersection(PMPI_Group group1, PMPI_Group group2, PMPI_Group *newgroup)
   ;
int PMPI_Group_range_excl(PMPI_Group group, int n, int ranges[][3], PMPI_Group *newgroup)
   ;
int PMPI_Group_range_incl(PMPI_Group group, int n, int ranges[][3], PMPI_Group *newgroup)
   ;
int PMPI_Group_rank(PMPI_Group group, int *rank);
int PMPI_Group_size(PMPI_Group group, int *size);
int PMPI_Group_translate_ranks(PMPI_Group group1, int n, const int ranks1[], PMPI_Group group2,
                               int ranks2[]);
int PMPI_Group_union(PMPI_Group group1, PMPI_Group group2, PMPI_Group *newgroup);
int PMPI_Info_create(PMPI_Info *info);
int PMPI_Info_create_env(int argc, char *argv[], PMPI_Info *info);
int PMPI_Info_delete(PMPI_Info info, const char *key);
int PMPI_Info_dup(PMPI_Info info, PMPI_Info *newinfo);
int PMPI_Info_free(PMPI_Info *info);
int PMPI_Info_get(PMPI_Info info, const char *key, int valuelen, char *value, int *flag)
   ;
int PMPI_Info_get_nkeys(PMPI_Info info, int *nkeys);
int PMPI_Info_get_nthkey(PMPI_Info info, int n, char *key);
int PMPI_Info_get_string(PMPI_Info info, const char *key, int *buflen, char *value, int *flag)
   ;
int PMPI_Info_get_valuelen(PMPI_Info info, const char *key, int *valuelen, int *flag)
   ;
int PMPI_Info_set(PMPI_Info info, const char *key, const char *value);
int PMPIX_Info_set_hex(PMPI_Info info, const char *key, const void *value, int value_size)
   ;
int PMPI_Abort(PMPI_Comm comm, int errorcode);
int PMPI_Comm_create_from_group(PMPI_Group group, const char *stringtag, PMPI_Info info,
                                PMPI_Errhandler errhandler, PMPI_Comm *newcomm);
int PMPI_Finalize(void);
int PMPI_Finalized(int *flag);
int PMPI_Group_from_session_pset(PMPI_Session session, const char *pset_name, PMPI_Group *newgroup)
   ;
int PMPI_Init(int *argc, char ***argv);
int PMPI_Init_thread(int *argc, char ***argv, int required, int *provided);
int PMPI_Initialized(int *flag);
int PMPI_Is_thread_main(int *flag);
int PMPI_Query_thread(int *provided);
int PMPI_Session_finalize(PMPI_Session *session);
int PMPI_Session_get_info(PMPI_Session session, PMPI_Info *info_used);
int PMPI_Session_get_nth_pset(PMPI_Session session, PMPI_Info info, int n, int *pset_len,
                              char *pset_name);
int PMPI_Session_get_num_psets(PMPI_Session session, PMPI_Info info, int *npset_names)
   ;
int PMPI_Session_get_pset_info(PMPI_Session session, const char *pset_name, PMPI_Info *info)
   ;
int PMPI_Session_init(PMPI_Info info, PMPI_Errhandler errhandler, PMPI_Session *session)
   ;
PMPI_Aint PMPI_Aint_add(PMPI_Aint base, PMPI_Aint disp);
PMPI_Aint PMPI_Aint_diff(PMPI_Aint addr1, PMPI_Aint addr2);
int PMPI_Get_library_version(char *version, int *resultlen);
int PMPI_Get_processor_name(char *name, int *resultlen);
int PMPI_Get_version(int *version, int *subversion);
int PMPI_Pcontrol(const int level, ...);
int PMPIX_GPU_query_support(int gpu_type, int *is_supported);
int PMPIX_Query_cuda_support(void);
int PMPIX_Query_ze_support(void);
int PMPIX_Query_hip_support(void);
int PMPI_Op_commutative(PMPI_Op op, int *commute);
int PMPI_Op_create(PMPI_User_function *user_fn, int commute, PMPI_Op *op);
int PMPI_Op_create_c(PMPI_User_function_c *user_fn, int commute, PMPI_Op *op);
int PMPI_Op_free(PMPI_Op *op);
int PMPI_Parrived(PMPI_Request request, int partition, int *flag);
int PMPI_Pready(int partition, PMPI_Request request);
int PMPI_Pready_list(int length, const int array_of_partitions[], PMPI_Request request)
   ;
int PMPI_Pready_range(int partition_low, int partition_high, PMPI_Request request);
int PMPI_Precv_init(void *buf, int partitions, PMPI_Count count, PMPI_Datatype datatype, int dest,
                    int tag, PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                    ;
int PMPI_Psend_init(const void *buf, int partitions, PMPI_Count count, PMPI_Datatype datatype,
                    int dest, int tag, PMPI_Comm comm, PMPI_Info info, PMPI_Request *request)
                    ;
int PMPI_Bsend(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag, PMPI_Comm comm)
    ;
int PMPI_Bsend_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                 PMPI_Comm comm) ;
int PMPI_Bsend_init(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag,
                    PMPI_Comm comm, PMPI_Request *request)
                    ;
int PMPI_Bsend_init_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                      PMPI_Comm comm, PMPI_Request *request)
                      ;
int PMPI_Buffer_attach(void *buffer, int size);
int PMPI_Buffer_attach_c(void *buffer, PMPI_Count size);
int PMPI_Buffer_detach(void *buffer_addr, int *size);
int PMPI_Buffer_detach_c(void *buffer_addr, PMPI_Count *size);
int PMPI_Ibsend(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag, PMPI_Comm comm,
                PMPI_Request *request) ;
int PMPI_Ibsend_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                  PMPI_Comm comm, PMPI_Request *request)
                  ;
int PMPI_Improbe(int source, int tag, PMPI_Comm comm, int *flag, PMPI_Message *message,
                 PMPI_Status *status);
int PMPI_Imrecv(void *buf, int count, PMPI_Datatype datatype, PMPI_Message *message,
                PMPI_Request *request) ;
int PMPI_Imrecv_c(void *buf, PMPI_Count count, PMPI_Datatype datatype, PMPI_Message *message,
                  PMPI_Request *request) ;
int PMPI_Iprobe(int source, int tag, PMPI_Comm comm, int *flag, PMPI_Status *status)
   ;
int PMPI_Irecv(void *buf, int count, PMPI_Datatype datatype, int source, int tag, PMPI_Comm comm,
               PMPI_Request *request) ;
int PMPI_Irecv_c(void *buf, PMPI_Count count, PMPI_Datatype datatype, int source, int tag,
                 PMPI_Comm comm, PMPI_Request *request)
                 ;
int PMPI_Irsend(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag, PMPI_Comm comm,
                PMPI_Request *request) ;
int PMPI_Irsend_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                  PMPI_Comm comm, PMPI_Request *request)
                  ;
int PMPI_Isend(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag, PMPI_Comm comm,
               PMPI_Request *request) ;
int PMPI_Isend_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                 PMPI_Comm comm, PMPI_Request *request)
                 ;
int PMPI_Isendrecv(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, int dest, int sendtag,
                   void *recvbuf, int recvcount, PMPI_Datatype recvtype, int source, int recvtag,
                   PMPI_Comm comm, PMPI_Request *request)
                   ;
int PMPI_Isendrecv_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype, int dest,
                     int sendtag, void *recvbuf, PMPI_Count recvcount, PMPI_Datatype recvtype,
                     int source, int recvtag, PMPI_Comm comm, PMPI_Request *request)
                     ;
int PMPI_Isendrecv_replace(void *buf, int count, PMPI_Datatype datatype, int dest, int sendtag,
                           int source, int recvtag, PMPI_Comm comm, PMPI_Request *request)
                           ;
int PMPI_Isendrecv_replace_c(void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest,
                             int sendtag, int source, int recvtag, PMPI_Comm comm,
                             PMPI_Request *request)
                             ;
int PMPI_Issend(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag, PMPI_Comm comm,
                PMPI_Request *request) ;
int PMPI_Issend_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                  PMPI_Comm comm, PMPI_Request *request)
                  ;
int PMPI_Mprobe(int source, int tag, PMPI_Comm comm, PMPI_Message *message, PMPI_Status *status)
   ;
int PMPI_Mrecv(void *buf, int count, PMPI_Datatype datatype, PMPI_Message *message,
               PMPI_Status *status) ;
int PMPI_Mrecv_c(void *buf, PMPI_Count count, PMPI_Datatype datatype, PMPI_Message *message,
                 PMPI_Status *status) ;
int PMPI_Probe(int source, int tag, PMPI_Comm comm, PMPI_Status *status);
int PMPI_Recv(void *buf, int count, PMPI_Datatype datatype, int source, int tag, PMPI_Comm comm,
              PMPI_Status *status) ;
int PMPI_Recv_c(void *buf, PMPI_Count count, PMPI_Datatype datatype, int source, int tag,
                PMPI_Comm comm, PMPI_Status *status)
                ;
int PMPI_Recv_init(void *buf, int count, PMPI_Datatype datatype, int source, int tag, PMPI_Comm comm,
                   PMPI_Request *request) ;
int PMPI_Recv_init_c(void *buf, PMPI_Count count, PMPI_Datatype datatype, int source, int tag,
                     PMPI_Comm comm, PMPI_Request *request)
                     ;
int PMPI_Rsend(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag, PMPI_Comm comm)
    ;
int PMPI_Rsend_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                 PMPI_Comm comm) ;
int PMPI_Rsend_init(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag,
                    PMPI_Comm comm, PMPI_Request *request)
                    ;
int PMPI_Rsend_init_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                      PMPI_Comm comm, PMPI_Request *request)
                      ;
int PMPI_Send(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag, PMPI_Comm comm)
    ;
int PMPI_Send_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                PMPI_Comm comm) ;
int PMPI_Send_init(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag,
                   PMPI_Comm comm, PMPI_Request *request)
                   ;
int PMPI_Send_init_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                     PMPI_Comm comm, PMPI_Request *request)
                     ;
int PMPI_Sendrecv(const void *sendbuf, int sendcount, PMPI_Datatype sendtype, int dest, int sendtag,
                  void *recvbuf, int recvcount, PMPI_Datatype recvtype, int source, int recvtag,
                  PMPI_Comm comm, PMPI_Status *status)
                  ;
int PMPI_Sendrecv_c(const void *sendbuf, PMPI_Count sendcount, PMPI_Datatype sendtype, int dest,
                    int sendtag, void *recvbuf, PMPI_Count recvcount, PMPI_Datatype recvtype,
                    int source, int recvtag, PMPI_Comm comm, PMPI_Status *status)
                    ;
int PMPI_Sendrecv_replace(void *buf, int count, PMPI_Datatype datatype, int dest, int sendtag,
                          int source, int recvtag, PMPI_Comm comm, PMPI_Status *status)
                          ;
int PMPI_Sendrecv_replace_c(void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest,
                            int sendtag, int source, int recvtag, PMPI_Comm comm,
                            PMPI_Status *status)
                            ;
int PMPI_Ssend(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag, PMPI_Comm comm)
    ;
int PMPI_Ssend_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                 PMPI_Comm comm) ;
int PMPI_Ssend_init(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag,
                    PMPI_Comm comm, PMPI_Request *request)
                    ;
int PMPI_Ssend_init_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                      PMPI_Comm comm, PMPI_Request *request)
                      ;
int PMPI_Cancel(PMPI_Request *request);
int PMPI_Grequest_complete(PMPI_Request request);
int PMPI_Grequest_start(PMPI_Grequest_query_function *query_fn, PMPI_Grequest_free_function *free_fn,
                        PMPI_Grequest_cancel_function *cancel_fn, void *extra_state,
                        PMPI_Request *request);
int PMPI_Request_free(PMPI_Request *request);
int PMPI_Request_get_status(PMPI_Request request, int *flag, PMPI_Status *status);
int PMPI_Start(PMPI_Request *request);
int PMPI_Startall(int count, PMPI_Request array_of_requests[]);
int PMPI_Status_set_cancelled(PMPI_Status *status, int flag);
int PMPI_Test(PMPI_Request *request, int *flag, PMPI_Status *status);
int PMPI_Test_cancelled(const PMPI_Status *status, int *flag);
int PMPI_Testall(int count, PMPI_Request array_of_requests[], int *flag,
                 PMPI_Status *array_of_statuses);
int PMPI_Testany(int count, PMPI_Request array_of_requests[], int *indx, int *flag,
                 PMPI_Status *status);
int PMPI_Testsome(int incount, PMPI_Request array_of_requests[], int *outcount,
                  int array_of_indices[], PMPI_Status *array_of_statuses);
int PMPI_Wait(PMPI_Request *request, PMPI_Status *status);
int PMPI_Waitall(int count, PMPI_Request array_of_requests[], PMPI_Status *array_of_statuses)
   ;
int PMPI_Waitany(int count, PMPI_Request array_of_requests[], int *indx, PMPI_Status *status)
   ;
int PMPI_Waitsome(int incount, PMPI_Request array_of_requests[], int *outcount,
                  int array_of_indices[], PMPI_Status *array_of_statuses);
int PMPIX_Grequest_start(PMPI_Grequest_query_function *query_fn, PMPI_Grequest_free_function *free_fn,
                         PMPI_Grequest_cancel_function *cancel_fn,
                         PMPIX_Grequest_poll_function *poll_fn, PMPIX_Grequest_wait_function *wait_fn,
                         void *extra_state, PMPI_Request *request);
int PMPIX_Grequest_class_create(PMPI_Grequest_query_function *query_fn,
                                PMPI_Grequest_free_function *free_fn,
                                PMPI_Grequest_cancel_function *cancel_fn,
                                PMPIX_Grequest_poll_function *poll_fn,
                                PMPIX_Grequest_wait_function *wait_fn,
                                PMPIX_Grequest_class *greq_class);
int PMPIX_Grequest_class_allocate(PMPIX_Grequest_class greq_class, void *extra_state,
                                  PMPI_Request *request);
int PMPI_Accumulate(const void *origin_addr, int origin_count, PMPI_Datatype origin_datatype,
                    int target_rank, PMPI_Aint target_disp, int target_count,
                    PMPI_Datatype target_datatype, PMPI_Op op, PMPI_Win win)
                    ;
int PMPI_Accumulate_c(const void *origin_addr, PMPI_Count origin_count, PMPI_Datatype origin_datatype,
                      int target_rank, PMPI_Aint target_disp, PMPI_Count target_count,
                      PMPI_Datatype target_datatype, PMPI_Op op, PMPI_Win win)
                      ;
int PMPI_Alloc_mem(PMPI_Aint size, PMPI_Info info, void *baseptr);
int PMPI_Compare_and_swap(const void *origin_addr, const void *compare_addr, void *result_addr,
                          PMPI_Datatype datatype, int target_rank, PMPI_Aint target_disp,
                          PMPI_Win win);
int PMPI_Fetch_and_op(const void *origin_addr, void *result_addr, PMPI_Datatype datatype,
                      int target_rank, PMPI_Aint target_disp, PMPI_Op op, PMPI_Win win)
                     ;
int PMPI_Free_mem(void *base);
int PMPI_Get(void *origin_addr, int origin_count, PMPI_Datatype origin_datatype, int target_rank,
             PMPI_Aint target_disp, int target_count, PMPI_Datatype target_datatype, PMPI_Win win)
             ;
int PMPI_Get_c(void *origin_addr, PMPI_Count origin_count, PMPI_Datatype origin_datatype,
               int target_rank, PMPI_Aint target_disp, PMPI_Count target_count,
               PMPI_Datatype target_datatype, PMPI_Win win)
               ;
int PMPI_Get_accumulate(const void *origin_addr, int origin_count, PMPI_Datatype origin_datatype,
                        void *result_addr, int result_count, PMPI_Datatype result_datatype,
                        int target_rank, PMPI_Aint target_disp, int target_count,
                        PMPI_Datatype target_datatype, PMPI_Op op, PMPI_Win win)
                        ;
int PMPI_Get_accumulate_c(const void *origin_addr, PMPI_Count origin_count,
                          PMPI_Datatype origin_datatype, void *result_addr, PMPI_Count result_count,
                          PMPI_Datatype result_datatype, int target_rank, PMPI_Aint target_disp,
                          PMPI_Count target_count, PMPI_Datatype target_datatype, PMPI_Op op,
                          PMPI_Win win)
                          ;
int PMPI_Put(const void *origin_addr, int origin_count, PMPI_Datatype origin_datatype,
             int target_rank, PMPI_Aint target_disp, int target_count, PMPI_Datatype target_datatype,
             PMPI_Win win) ;
int PMPI_Put_c(const void *origin_addr, PMPI_Count origin_count, PMPI_Datatype origin_datatype,
               int target_rank, PMPI_Aint target_disp, PMPI_Count target_count,
               PMPI_Datatype target_datatype, PMPI_Win win)
               ;
int PMPI_Raccumulate(const void *origin_addr, int origin_count, PMPI_Datatype origin_datatype,
                     int target_rank, PMPI_Aint target_disp, int target_count,
                     PMPI_Datatype target_datatype, PMPI_Op op, PMPI_Win win, PMPI_Request *request)
                     ;
int PMPI_Raccumulate_c(const void *origin_addr, PMPI_Count origin_count,
                       PMPI_Datatype origin_datatype, int target_rank, PMPI_Aint target_disp,
                       PMPI_Count target_count, PMPI_Datatype target_datatype, PMPI_Op op, PMPI_Win win,
                       PMPI_Request *request)
                       ;
int PMPI_Rget(void *origin_addr, int origin_count, PMPI_Datatype origin_datatype, int target_rank,
              PMPI_Aint target_disp, int target_count, PMPI_Datatype target_datatype, PMPI_Win win,
              PMPI_Request *request) ;
int PMPI_Rget_c(void *origin_addr, PMPI_Count origin_count, PMPI_Datatype origin_datatype,
                int target_rank, PMPI_Aint target_disp, PMPI_Count target_count,
                PMPI_Datatype target_datatype, PMPI_Win win, PMPI_Request *request)
                ;
int PMPI_Rget_accumulate(const void *origin_addr, int origin_count, PMPI_Datatype origin_datatype,
                         void *result_addr, int result_count, PMPI_Datatype result_datatype,
                         int target_rank, PMPI_Aint target_disp, int target_count,
                         PMPI_Datatype target_datatype, PMPI_Op op, PMPI_Win win,
                         PMPI_Request *request)
                         ;
int PMPI_Rget_accumulate_c(const void *origin_addr, PMPI_Count origin_count,
                           PMPI_Datatype origin_datatype, void *result_addr, PMPI_Count result_count,
                           PMPI_Datatype result_datatype, int target_rank, PMPI_Aint target_disp,
                           PMPI_Count target_count, PMPI_Datatype target_datatype, PMPI_Op op,
                           PMPI_Win win, PMPI_Request *request)
                           ;
int PMPI_Rput(const void *origin_addr, int origin_count, PMPI_Datatype origin_datatype,
              int target_rank, PMPI_Aint target_disp, int target_count, PMPI_Datatype target_datatype,
              PMPI_Win win, PMPI_Request *request)
              ;
int PMPI_Rput_c(const void *origin_addr, PMPI_Count origin_count, PMPI_Datatype origin_datatype,
                int target_rank, PMPI_Aint target_disp, PMPI_Count target_count,
                PMPI_Datatype target_datatype, PMPI_Win win, PMPI_Request *request)
                ;
int PMPI_Win_allocate(PMPI_Aint size, int disp_unit, PMPI_Info info, PMPI_Comm comm, void *baseptr,
                      PMPI_Win *win);
int PMPI_Win_allocate_c(PMPI_Aint size, PMPI_Aint disp_unit, PMPI_Info info, PMPI_Comm comm,
                        void *baseptr, PMPI_Win *win);
int PMPI_Win_allocate_shared(PMPI_Aint size, int disp_unit, PMPI_Info info, PMPI_Comm comm,
                             void *baseptr, PMPI_Win *win);
int PMPI_Win_allocate_shared_c(PMPI_Aint size, PMPI_Aint disp_unit, PMPI_Info info, PMPI_Comm comm,
                               void *baseptr, PMPI_Win *win);
int PMPI_Win_attach(PMPI_Win win, void *base, PMPI_Aint size);
int PMPI_Win_complete(PMPI_Win win);
int PMPI_Win_create(void *base, PMPI_Aint size, int disp_unit, PMPI_Info info, PMPI_Comm comm,
                    PMPI_Win *win);
int PMPI_Win_create_c(void *base, PMPI_Aint size, PMPI_Aint disp_unit, PMPI_Info info, PMPI_Comm comm,
                      PMPI_Win *win);
int PMPI_Win_create_dynamic(PMPI_Info info, PMPI_Comm comm, PMPI_Win *win);
int PMPI_Win_detach(PMPI_Win win, const void *base);
int PMPI_Win_fence(int assert, PMPI_Win win);
int PMPI_Win_flush(int rank, PMPI_Win win);
int PMPI_Win_flush_all(PMPI_Win win);
int PMPI_Win_flush_local(int rank, PMPI_Win win);
int PMPI_Win_flush_local_all(PMPI_Win win);
int PMPI_Win_free(PMPI_Win *win);
int PMPI_Win_get_group(PMPI_Win win, PMPI_Group *group);
int PMPI_Win_get_info(PMPI_Win win, PMPI_Info *info_used);
int PMPI_Win_get_name(PMPI_Win win, char *win_name, int *resultlen);
int PMPI_Win_lock(int lock_type, int rank, int assert, PMPI_Win win);
int PMPI_Win_lock_all(int assert, PMPI_Win win);
int PMPI_Win_post(PMPI_Group group, int assert, PMPI_Win win);
int PMPI_Win_set_info(PMPI_Win win, PMPI_Info info);
int PMPI_Win_set_name(PMPI_Win win, const char *win_name);
int PMPI_Win_shared_query(PMPI_Win win, int rank, PMPI_Aint *size, int *disp_unit, void *baseptr)
   ;
int PMPI_Win_shared_query_c(PMPI_Win win, int rank, PMPI_Aint *size, PMPI_Aint *disp_unit,
                            void *baseptr);
int PMPI_Win_start(PMPI_Group group, int assert, PMPI_Win win);
int PMPI_Win_sync(PMPI_Win win);
int PMPI_Win_test(PMPI_Win win, int *flag);
int PMPI_Win_unlock(int rank, PMPI_Win win);
int PMPI_Win_unlock_all(PMPI_Win win);
int PMPI_Win_wait(PMPI_Win win);
int PMPI_Close_port(const char *port_name);
int PMPI_Comm_accept(const char *port_name, PMPI_Info info, int root, PMPI_Comm comm,
                     PMPI_Comm *newcomm);
int PMPI_Comm_connect(const char *port_name, PMPI_Info info, int root, PMPI_Comm comm,
                      PMPI_Comm *newcomm);
int PMPI_Comm_disconnect(PMPI_Comm *comm);
int PMPI_Comm_get_parent(PMPI_Comm *parent);
int PMPI_Comm_join(int fd, PMPI_Comm *intercomm);
int PMPI_Comm_spawn(const char *command, char *argv[], int maxprocs, PMPI_Info info, int root,
                    PMPI_Comm comm, PMPI_Comm *intercomm, int array_of_errcodes[]);
int PMPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[],
                             const int array_of_maxprocs[], const PMPI_Info array_of_info[],
                             int root, PMPI_Comm comm, PMPI_Comm *intercomm, int array_of_errcodes[])
                            ;
int PMPI_Lookup_name(const char *service_name, PMPI_Info info, char *port_name);
int PMPI_Open_port(PMPI_Info info, char *port_name);
int PMPI_Publish_name(const char *service_name, PMPI_Info info, const char *port_name)
   ;
int PMPI_Unpublish_name(const char *service_name, PMPI_Info info, const char *port_name)
   ;
int PMPIX_Stream_create(PMPI_Info info, PMPIX_Stream *stream);
int PMPIX_Stream_free(PMPIX_Stream *stream);
int PMPIX_Stream_comm_create(PMPI_Comm comm, PMPIX_Stream stream, PMPI_Comm *newcomm)
   ;
int PMPIX_Stream_comm_create_multiplex(PMPI_Comm comm, int count, PMPIX_Stream array_of_streams[],
                                       PMPI_Comm *newcomm);
int PMPIX_Comm_get_stream(PMPI_Comm comm, int idx, PMPIX_Stream *stream);
int PMPIX_Stream_progress(PMPIX_Stream stream);
int PMPIX_Start_progress_thread(PMPIX_Stream stream);
int PMPIX_Stop_progress_thread(PMPIX_Stream stream);
int PMPIX_Stream_send(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag,
                      PMPI_Comm comm, int source_stream_index, int dest_stream_index)
                      ;
int PMPIX_Stream_send_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                        PMPI_Comm comm, int source_stream_index, int dest_stream_index)
                        ;
int PMPIX_Stream_isend(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag,
                       PMPI_Comm comm, int source_stream_index, int dest_stream_index,
                       PMPI_Request *request)
                       ;
int PMPIX_Stream_isend_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                         PMPI_Comm comm, int source_stream_index, int dest_stream_index,
                         PMPI_Request *request)
                         ;
int PMPIX_Stream_recv(void *buf, int count, PMPI_Datatype datatype, int source, int tag,
                      PMPI_Comm comm, int source_stream_index, int dest_stream_index,
                      PMPI_Status *status) ;
int PMPIX_Stream_recv_c(void *buf, PMPI_Count count, PMPI_Datatype datatype, int source, int tag,
                        PMPI_Comm comm, int source_stream_index, int dest_stream_index,
                        PMPI_Status *status) ;
int PMPIX_Stream_irecv(void *buf, int count, PMPI_Datatype datatype, int source, int tag,
                       PMPI_Comm comm, int source_stream_index, int dest_stream_index,
                       PMPI_Request *request)
                       ;
int PMPIX_Stream_irecv_c(void *buf, PMPI_Count count, PMPI_Datatype datatype, int source, int tag,
                         PMPI_Comm comm, int source_stream_index, int dest_stream_index,
                         PMPI_Request *request)
                         ;
int PMPIX_Send_enqueue(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag,
                       PMPI_Comm comm) ;
int PMPIX_Send_enqueue_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest, int tag,
                         PMPI_Comm comm) ;
int PMPIX_Recv_enqueue(void *buf, int count, PMPI_Datatype datatype, int source, int tag,
                       PMPI_Comm comm, PMPI_Status *status)
                       ;
int PMPIX_Recv_enqueue_c(void *buf, PMPI_Count count, PMPI_Datatype datatype, int source, int tag,
                         PMPI_Comm comm, PMPI_Status *status)
                         ;
int PMPIX_Isend_enqueue(const void *buf, int count, PMPI_Datatype datatype, int dest, int tag,
                        PMPI_Comm comm, PMPI_Request *request)
                        ;
int PMPIX_Isend_enqueue_c(const void *buf, PMPI_Count count, PMPI_Datatype datatype, int dest,
                          int tag, PMPI_Comm comm, PMPI_Request *request)
                          ;
int PMPIX_Irecv_enqueue(void *buf, int count, PMPI_Datatype datatype, int source, int tag,
                        PMPI_Comm comm, PMPI_Request *request)
                        ;
int PMPIX_Irecv_enqueue_c(void *buf, PMPI_Count count, PMPI_Datatype datatype, int source, int tag,
                          PMPI_Comm comm, PMPI_Request *request)
                          ;
int PMPIX_Wait_enqueue(PMPI_Request *request, PMPI_Status *status);
int PMPIX_Waitall_enqueue(int count, PMPI_Request array_of_requests[],
                          PMPI_Status *array_of_statuses);
int PMPIX_Allreduce_enqueue(const void *sendbuf, void *recvbuf, int count, PMPI_Datatype datatype,
                            PMPI_Op op, PMPI_Comm comm)
                            ;
int PMPIX_Allreduce_enqueue_c(const void *sendbuf, void *recvbuf, PMPI_Count count,
                              PMPI_Datatype datatype, PMPI_Op op, PMPI_Comm comm)
                              ;
int PMPIX_Threadcomm_init(PMPI_Comm comm, int num_threads, PMPI_Comm *newthreadcomm)
   ;
int PMPIX_Threadcomm_free(PMPI_Comm *threadcomm);
int PMPIX_Threadcomm_start(PMPI_Comm threadcomm);
int PMPIX_Threadcomm_finish(PMPI_Comm threadcomm);
double PMPI_Wtick(void);
double PMPI_Wtime(void);
int PMPI_Cart_coords(PMPI_Comm comm, int rank, int maxdims, int coords[]);
int PMPI_Cart_create(PMPI_Comm comm_old, int ndims, const int dims[], const int periods[],
                     int reorder, PMPI_Comm *comm_cart);
int PMPI_Cart_get(PMPI_Comm comm, int maxdims, int dims[], int periods[], int coords[])
   ;
int PMPI_Cart_map(PMPI_Comm comm, int ndims, const int dims[], const int periods[], int *newrank)
   ;
int PMPI_Cart_rank(PMPI_Comm comm, const int coords[], int *rank);
int PMPI_Cart_shift(PMPI_Comm comm, int direction, int disp, int *rank_source, int *rank_dest)
   ;
int PMPI_Cart_sub(PMPI_Comm comm, const int remain_dims[], PMPI_Comm *newcomm);
int PMPI_Cartdim_get(PMPI_Comm comm, int *ndims);
int PMPI_Dims_create(int nnodes, int ndims, int dims[]);
int PMPI_Dist_graph_create(PMPI_Comm comm_old, int n, const int sources[], const int degrees[],
                           const int destinations[], const int weights[], PMPI_Info info,
                           int reorder, PMPI_Comm *comm_dist_graph);
int PMPI_Dist_graph_create_adjacent(PMPI_Comm comm_old, int indegree, const int sources[],
                                    const int sourceweights[], int outdegree,
                                    const int destinations[], const int destweights[],
                                    PMPI_Info info, int reorder, PMPI_Comm *comm_dist_graph)
                                   ;
int PMPI_Dist_graph_neighbors(PMPI_Comm comm, int maxindegree, int sources[], int sourceweights[],
                              int maxoutdegree, int destinations[], int destweights[])
                             ;
int PMPI_Dist_graph_neighbors_count(PMPI_Comm comm, int *indegree, int *outdegree, int *weighted)
   ;
int PMPI_Graph_create(PMPI_Comm comm_old, int nnodes, const int indx[], const int edges[],
                      int reorder, PMPI_Comm *comm_graph);
int PMPI_Graph_get(PMPI_Comm comm, int maxindex, int maxedges, int indx[], int edges[]);
int PMPI_Graph_map(PMPI_Comm comm, int nnodes, const int indx[], const int edges[], int *newrank);
int PMPI_Graph_neighbors(PMPI_Comm comm, int rank, int maxneighbors, int neighbors[]);
int PMPI_Graph_neighbors_count(PMPI_Comm comm, int rank, int *nneighbors);
int PMPI_Graphdims_get(PMPI_Comm comm, int *nnodes, int *nedges);
int PMPI_Topo_test(PMPI_Comm comm, int *status);

#endif /* PMPI_PROTO_H_INCLUDED */
