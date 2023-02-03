#include "mpi_abi.h"
#include "pmpi.h"

MPI_Status * MPI_STATUS_IGNORE = (MPI_Status *) PMPI_STATUS_IGNORE;
MPI_Status * MPI_STATUSES_IGNORE = (MPI_Status *) PMPI_STATUSES_IGNORE;
int MPI_PROC_NULL = PMPI_PROC_NULL;
int MPI_ANY_SOURCE = PMPI_ANY_SOURCE;
int MPI_ANY_TAG = PMPI_ANY_TAG;

MPI_Comm MPI_COMM_NULL = (MPI_Comm) PMPI_COMM_NULL;
MPI_Comm MPI_COMM_WORLD = (MPI_Comm) PMPI_COMM_WORLD;
MPI_Comm MPI_COMM_SELF = (MPI_Comm) PMPI_COMM_SELF;

MPI_Datatype MPI_DATATYPE_NULL = (MPI_Datatype) PMPI_DATATYPE_NULL;
MPI_Datatype MPI_INT = (MPI_Datatype) PMPI_INT;
MPI_Datatype MPI_DOUBLE = (MPI_Datatype) PMPI_DOUBLE;

MPI_Request MPI_REQUEST_NULL = (MPI_Request) PMPI_REQUEST_NULL;

void ABI_Status_to_pmpi(MPI_Status * in, PMPI_Status * out)
{
    out->MPI_SOURCE = in->MPI_SOURCE;
    out->MPI_TAG = in->MPI_TAG;
    out->MPI_ERROR = in->MPI_ERROR;
    out->count_lo = in->reserved[0];
    out->count_hi_and_cancelled = in->reserved[1];
}

void ABI_Status_from_pmpi(PMPI_Status * in, MPI_Status * out)
{
    out->MPI_SOURCE = in->MPI_SOURCE;
    out->MPI_TAG = in->MPI_TAG;
    out->MPI_ERROR = in->MPI_ERROR;
    out->reserved[0] = in->count_lo;
    out->reserved[1] = in->count_hi_and_cancelled;
}
