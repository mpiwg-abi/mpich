#include "mpi_abi_internal.h"

/* hacky way with the header.
 * We need the types in mpi.h but not the MPI func decls in mpi_proto.h
 * But we also need the PMPI func decls, so separating them in mpi_pmpi.h
 */
#define MPICH_SUPPRESS_PROTOTYPES
#include "mpi.h"
#include "mpi_pmpi.h"

int MPI_Init(int *argc, char ***argv)
{
    return PMPI_Init(argc, argv);
}

int MPI_Finalize(void)
{
    return PMPI_Finalize();
}

int MPI_Send(const void *buf, int count, MPIABI_Datatype datatype, int dest, int tag, MPIABI_Comm comm)
{
    MPI_Datatype _datatype = (MPI_Datatype) MPIABI_Translate(datatype);
    MPI_Comm _comm = (MPI_Comm) MPIABI_Translate(comm);
    return PMPI_Send(buf, count, _datatype, dest, tag, _comm);
}

int MPI_Recv(void *buf, int count, MPIABI_Datatype datatype, int source, int tag, MPIABI_Comm comm, MPIABI_Status *status)
{
    MPI_Datatype _datatype = (MPI_Datatype) MPIABI_Translate(datatype);
    MPI_Comm _comm = (MPI_Comm) MPIABI_Translate(comm);
    MPI_Status *_status = (MPI_Status *) MPIABI_Translate(status);
    return PMPI_Recv(buf, count, _datatype, source, tag, _comm, _status);
}

int MPI_Comm_size(MPIABI_Comm comm, int *size)
{
    MPI_Comm _comm = (MPI_Comm) MPIABI_Translate(comm);
    return PMPI_Comm_size(_comm, size);
}

int MPI_Comm_rank(MPIABI_Comm comm, int *rank)
{
    MPI_Comm _comm = (MPI_Comm) MPIABI_Translate(comm);
    return PMPI_Comm_rank(_comm, rank);
}

