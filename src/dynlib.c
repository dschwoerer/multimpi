#include "mpi.h"
#include <stdio.h>

MPI_Comm mpi_COMM_WORLD = MPI_COMM_WORLD;
MPI_Comm mpi_COMM_NULL = MPI_COMM_NULL;
MPI_Datatype mpi_DOUBLE = MPI_DOUBLE;
MPI_Datatype mpi_INT = MPI_INT;
MPI_Datatype mpi_BYTE = MPI_BYTE;
MPI_Datatype mpi_C_BOOL = MPI_C_BOOL;
MPI_Op mpi_MAX = MPI_MAX;
MPI_Op mpi_MIN = MPI_MIN;
MPI_Op mpi_SUM = MPI_SUM;
MPI_Op mpi_LOR = MPI_LOR;
MPI_Op mpi_BOR = MPI_BOR;
MPI_Request mpi_REQUEST_NULL = MPI_REQUEST_NULL;
MPI_Group mpi_GROUP_EMPTY = MPI_GROUP_EMPTY;
int mpi_SUCCESS = MPI_SUCCESS;
int mpi_UNDEFINED = MPI_UNDEFINED;

int mpi_Init(int *argc, char ***argv) { return MPI_Init(argc, argv); }

int mpi_Initialized(int *flag) { return MPI_Initialized(flag); }

int mpi_Comm_size(void *comm, int *size) { return MPI_Comm_size(comm, size); }

int mpi_Comm_rank(void *comm, int *rank) { return MPI_Comm_rank(comm, rank); }

double mpi_Wtime() { return MPI_Wtime(); }

int mpi_Finalize() { return MPI_Finalize(); }

int mpi_Allreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, void *comm) { return MPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm); }

int mpi_Waitany(int count, MPI_Request *array_of_requests, int *indx, MPI_Status * status) { return MPI_Waitany(count, array_of_requests, indx, status); }

int mpi_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, void *comm) { return MPI_Send(buf, count, datatype, dest, tag, comm); }

int mpi_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, void *comm, MPI_Request * request) { return MPI_Irecv(buf, count, datatype, source, tag, comm, request); }

int mpi_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, void *comm, MPI_Status * status) { return MPI_Recv(buf, count, datatype, source, tag, comm, status); }

int mpi_Comm_free(void *comm) { return MPI_Comm_free(comm); }

int mpi_Comm_dup(void *comm, void **newcomm) { return MPI_Comm_dup(comm, newcomm); }

int mpi_Barrier(void *comm) { return MPI_Barrier(comm); }

int mpi_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype * newtype) { return MPI_Type_vector(count, blocklength, stride, oldtype, newtype); }

int mpi_Type_commit(MPI_Datatype * datatype) { return MPI_Type_commit(datatype); }

int mpi_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, void *comm, MPI_Request * request) { return MPI_Isend(buf, count, datatype, dest, tag, comm, request); }

int mpi_Waitall(int count, MPI_Request* array_of_requests, MPI_Status * array_of_statuses) { return MPI_Waitall(count, array_of_requests, array_of_statuses); }

int mpi_Type_free(MPI_Datatype * datatype) { return MPI_Type_free(datatype); }

int mpi_Comm_split(void *comm, int color, int key, void ** newcomm) { return MPI_Comm_split(comm, color, key, newcomm); }

int mpi_Wait(MPI_Request * request, MPI_Status * status) { return MPI_Wait(request, status); }

int mpi_Group_free(MPI_Group * group) { return MPI_Group_free(group); }

int mpi_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group * newgroup) { return MPI_Group_union(group1, group2, newgroup); }

int mpi_Comm_create(void *comm, MPI_Group group, void ** newcomm) { return MPI_Comm_create(comm, group, newcomm); }

int mpi_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group * newgroup) { return MPI_Group_range_incl(group, n, ranges, newgroup); }

int mpi_Comm_group(void *comm, MPI_Group * group) { return MPI_Comm_group(comm, group); }
