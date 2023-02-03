#include "mpi_abi.h"
#include "mpi_abi_internal.h"

#include "pmpi.h"

int MPI_Init(int *argc, char ***argv)
{
    return PMPI_Init(argc, argv);
}

int MPI_Finalize(void)
{
    return PMPI_Finalize();
}

int MPI_Abort(MPI_Comm comm, int errorcode)
{
    return PMPI_Abort(COMM_TO_PMPI(comm), errorcode);
}

int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
    return PMPI_Send(buf, count, DATATYPE_TO_PMPI(datatype), dest, tag, COMM_TO_PMPI(comm));
}

int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm,
             MPI_Status * status)
{
    PMPI_Status status_i;
    PMPI_Status *status_p;
    if (status == MPI_STATUS_IGNORE) {
        status_p = PMPI_STATUS_IGNORE;
    } else {
        status_p = &status_i;
        ABI_Status_to_pmpi(status, status_p);
    }

    int ret = PMPI_Recv(buf, count, DATATYPE_TO_PMPI(datatype), source, tag,
                        COMM_TO_PMPI(comm), status_p);

    if (status != MPI_STATUS_IGNORE) {
        ABI_Status_from_pmpi(status_p, status);
    }

    return ret;
}

int MPI_Comm_size(MPI_Comm comm, int *size)
{
    return PMPI_Comm_size(COMM_TO_PMPI(comm), size);
}

int MPI_Comm_rank(MPI_Comm comm, int *rank)
{
    return PMPI_Comm_rank(COMM_TO_PMPI(comm), rank);
}

int MPI_Comm_free(MPI_Comm *comm)
{
    PMPI_Comm comm_i;
    comm_i = COMM_TO_PMPI(*comm);

    int ret = PMPI_Comm_free(&comm_i);

    *comm = COMM_FROM_PMPI(comm_i);

    return ret;
}

int MPI_Type_free(MPI_Datatype *datatype)
{
    PMPI_Datatype datatype_i;
    datatype_i = DATATYPE_TO_PMPI(*datatype);

    int ret = PMPI_Type_free(&datatype_i);

    *datatype = DATATYPE_FROM_PMPI(datatype_i);

    return ret;
}
