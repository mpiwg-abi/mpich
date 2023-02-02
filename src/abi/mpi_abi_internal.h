#ifndef __MPI_ABI_INTERNAL_H_INCLUDED
#define __MPI_ABI_INTERNAL_H_INCLUDED

#include <stdint.h>

typedef intptr_t MPIABI_Comm;
typedef intptr_t MPIABI_Datatype;
typedef intptr_t MPIABI_Request;

#if 1
typedef struct MPIABI_Status MPIABI_Status;
#else
typedef struct MPIABI_Status {
    int MPI_SOURCE;
    int MPI_TAG;
    int MPI_ERROR;
    int reserved[5];
} MPIABI_Status;
#endif

#define MPIABI_STATUS_IGNORE -1
#define MPIABI_STATUSES_IGNORE -2
#define MPIABI_PROC_NULL -3
#define MPIABI_ANY_SOURCE -4
#define MPIABI_ANY_TAG -5

#define MPIABI_COMM_WORLD 1
#define MPIABI_COMM_SELF  2

#define MPIABI_INT  0x100
#define MPIABI_DOUBLE 0x101

/* core set */
int MPI_Init(int *argc, char ***argv);
int MPI_Finalize(void);
int MPI_Send(const void *buf, int count, MPIABI_Datatype datatype, int dest, int tag, MPIABI_Comm comm);
int MPI_Recv(void *buf, int count, MPIABI_Datatype datatype, int source, int tag, MPIABI_Comm comm, MPIABI_Status *status);
int MPI_Wait(MPIABI_Request *request, MPIABI_Status *status);
int MPI_Comm_size(MPIABI_Comm comm, int *size);
int MPI_Comm_rank(MPIABI_Comm comm, int *rank);

/* 2nd set */
int MPI_Init_thread(int *argc, char ***argv, int required, int *provided);
int MPI_Isend(const void *buf, int count, MPIABI_Datatype datatype, int dest, int tag, MPIABI_Comm comm, MPIABI_Request *request);
int MPI_Irecv(void *buf, int count, MPIABI_Datatype datatype, int source, int tag, MPIABI_Comm comm, MPIABI_Request *request);
int MPI_Waitall(int count, MPIABI_Request array_of_requests[], MPIABI_Status *array_of_statuses);

/* 3rd set */
int MPI_Comm_free(MPIABI_Comm *comm);
int MPI_Type_free(MPIABI_Datatype *datatype);

int MPI_Comm_dup(MPIABI_Comm comm, MPIABI_Comm *newcomm);
int MPI_Type_contiguous(int count, MPIABI_Datatype oldtype, MPIABI_Datatype *newtype);

intptr_t MPIABI_Translate(intptr_t value);

#endif /* __MPI_ABI_INTERNAL_H_INCLUDED */
