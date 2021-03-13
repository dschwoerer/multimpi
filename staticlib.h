typedef void *MPI_Comm;

extern MPI_Comm MPI_COMM_WORLD;

int MPI_Init(int *argc, char ***argv);

int MPI_Comm_size(MPI_Comm comm, int *size);

int MPI_Comm_rank(MPI_Comm comm, int *rank);

double MPI_Wtime();

int MPI_Finalize();
