typedef void* MPI_Comm;

int mpi_Init(int * argc, char *** argv);

int mpi_Comm_size(MPI_Comm comm, int * size);
