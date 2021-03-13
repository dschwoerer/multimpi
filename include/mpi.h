typedef void *MPI_Comm;
typedef double MPI_DOUBLE;
typedef int MPI_INT;
extern int MPI_SUCCESS;

extern MPI_Comm MPI_COMM_WORLD;
extern MPI_Comm MPI_COMM_NULL;

int MPI_Init(int *argc, char ***argv);

int MPI_Initialized(int *flag);

int MPI_Comm_size(MPI_Comm comm, int *size);

int MPI_Comm_rank(MPI_Comm comm, int *rank);

double MPI_Wtime();

int MPI_Finalize();
