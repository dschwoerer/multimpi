#include "mpi.h"
#include <stdio.h>

MPI_Comm mpi_COMM_WORLD = MPI_COMM_WORLD;
MPI_Comm mpi_COMM_NULL = MPI_COMM_NULL;

int mpi_Init(int *argc, char ***argv) { return MPI_Init(argc, argv); }

int mpi_Initialized(int *flag) { return MPI_Initialized(flag); }

int mpi_Comm_size(void *comm, int *size) { return MPI_Comm_size(comm, size); }

int mpi_Comm_rank(void *comm, int *rank) { return MPI_Comm_rank(comm, rank); }

double mpi_Wtime() { return MPI_Wtime(); }

int mpi_Finalize() { return MPI_Finalize(); }
