#ifndef __MPI_ABI_INTERNAL_H_INCLUDED
#define __MPI_ABI_INTERNAL_H_INCLUDED

#include <stdint.h>
#include "mpi_abi.h"
#include "pmpi.h"

/* intptr_t to int, directly cast */
#define COMM_TO_PMPI(h)      ((PMPI_Comm) (h))
#define DATATYPE_TO_PMPI(h)  ((PMPI_Datatype) (h))
#define REQUEST_TO_PMPI(h)   ((PMPI_Request) (h))

/* int to intptr_t, directly cast */
#define COMM_FROM_PMPI(h)      ((MPI_Comm) (h))
#define DATATYPE_FROM_PMPI(h)  ((MPI_Datatype) (h))
#define REQUEST_FROM_PMPI(h)   ((MPI_Request) (h))

void ABI_Status_to_pmpi(MPI_Status * in, PMPI_Status * out);
void ABI_Status_from_pmpi(PMPI_Status * in, MPI_Status * out);

#endif /* __MPI_ABI_INTERNAL_H_INCLUDED */
