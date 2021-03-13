#include "mpi.h"

int mpi_Init(int * argc, char *** argv){
  return MPI_Init(argc, argv);
}

int mpi_Comm_size( void* comm, int * size){
  return MPI_Comm_size(comm, size);
}
