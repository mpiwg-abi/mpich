#ifndef MPI_ABI_H_INCLUDED
#define MPI_ABI_H_INCLUDED

#include <stdint.h>

typedef intptr_t MPI_Comm;
typedef intptr_t MPI_Datatype;
typedef intptr_t MPI_Request;

typedef intptr_t MPI_Aint;
typedef long long MPI_Offset;
typedef MPI_Offset MPI_Count;

typedef struct MPI_Status {
    int MPI_SOURCE;
    int MPI_TAG;
    int MPI_ERROR;
    int reserved[5];
} MPI_Status;

extern MPI_Status * MPI_STATUS_IGNORE;
extern MPI_Status * MPI_STATUSES_IGNORE;
extern int MPI_PROC_NULL;
extern int MPI_ANY_SOURCE;
extern int MPI_ANY_TAG;

extern MPI_Comm MPI_COMM_NULL;
extern MPI_Comm MPI_COMM_WORLD;
extern MPI_Comm MPI_COMM_SELF;

extern MPI_Datatype MPI_DATATYPE_NULL;
extern MPI_Datatype MPI_INT;
extern MPI_Datatype MPI_DOUBLE;

extern MPI_Request MPI_REQUEST_NULL;

/* core set */
int MPI_Init(int *argc, char ***argv);
int MPI_Finalize(void);
int MPI_Abort(MPI_Comm comm, int errorcode);
int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status);
int MPI_Wait(MPI_Request *request, MPI_Status *status);
int MPI_Comm_size(MPI_Comm comm, int *size);
int MPI_Comm_rank(MPI_Comm comm, int *rank);

/* 2nd set */
int MPI_Init_thread(int *argc, char ***argv, int required, int *provided);
int MPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request *request);
int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request *request);
int MPI_Waitall(int count, MPI_Request array_of_requests[], MPI_Status *array_of_statuses);

/* 3rd set */
int MPI_Comm_free(MPI_Comm *comm);
int MPI_Type_free(MPI_Datatype *datatype);

int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm);
int MPI_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype);

#endif /* MPI_ABI_H_INCLUDED */
