#ifdef __cplusplus
extern "C" {
#endif
typedef void * MPI_Comm;
typedef void * MPI_Datatype;
typedef void * MPI_Op;
typedef void * MPI_Request;
typedef void * MPI_Status;
typedef void * MPI_Group;
extern MPI_Comm MPI_COMM_WORLD;
extern MPI_Comm MPI_COMM_NULL;
extern MPI_Datatype MPI_DOUBLE;
extern MPI_Datatype MPI_INT;
extern MPI_Datatype MPI_BYTE;
extern MPI_Datatype MPI_C_BOOL;
extern MPI_Op MPI_MAX;
extern MPI_Op MPI_MIN;
extern MPI_Op MPI_SUM;
extern MPI_Op MPI_LOR;
extern MPI_Op MPI_BOR;
extern MPI_Request MPI_REQUEST_NULL;
extern MPI_Group MPI_GROUP_EMPTY;
extern int MPI_SUCCESS;
extern int MPI_UNDEFINED;

int MPI_Init(int *argc, char ***argv);

int MPI_Initialized(int *flag);

int MPI_Comm_size(MPI_Comm comm, int *size);

int MPI_Comm_rank(MPI_Comm comm, int *rank);

double MPI_Wtime();

int MPI_Finalize();

int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);

int MPI_Waitany(int count, MPI_Request *array_of_requests, int *indx, MPI_Status * status);

int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);

int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request * request);

int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status * status);

int MPI_Comm_free(MPI_Comm comm);

int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm);

int MPI_Barrier(MPI_Comm comm);

int MPI_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype * newtype);

int MPI_Type_commit(MPI_Datatype * datatype);

int MPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request * request);

int MPI_Waitall(int count, MPI_Request* array_of_requests, MPI_Status * array_of_statuses);

int MPI_Type_free(MPI_Datatype * datatype);

int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm * newcomm);

int MPI_Wait(MPI_Request * request, MPI_Status * status);

int MPI_Group_free(MPI_Group * group);

int MPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group * newgroup);

int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm * newcomm);

int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group * newgroup);

int MPI_Comm_group(MPI_Comm comm, MPI_Group * group);

#ifdef __cplusplus
}
#endif

