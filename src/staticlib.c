#include "mpi.h"
#include "dlfcn.h"
#include "stdio.h"

void *handle = 0;

MPI_Comm MPI_COMM_WORLD;
MPI_Comm MPI_COMM_NULL;
MPI_Datatype MPI_DOUBLE;
MPI_Datatype MPI_INT;
MPI_Datatype MPI_BYTE;
MPI_Datatype MPI_C_BOOL;
MPI_Op MPI_MAX;
MPI_Op MPI_MIN;
MPI_Op MPI_SUM;
MPI_Op MPI_LOR;
MPI_Op MPI_BOR;
MPI_Request MPI_REQUEST_NULL;
MPI_Group MPI_GROUP_EMPTY;
int MPI_SUCCESS;
int MPI_UNDEFINED;

int myinit(){
  if (handle)
    return 0;
  const char * mylib;
  handle = dlopen("libmpi.so.40", RTLD_NOW);
  if (handle){
    dlclose(handle);
    mylib= "lib/openmpi.so";
  } else {
    handle = dlopen("libmpi.so.12", RTLD_NOW);
    if (handle){
      dlclose(handle);
      mylib= "lib/mpich.so";
    } else {
      printf("could not find a suitable mpilibrary. Ensure LD_LIBRARY_PATH is correct");
      return 1;
    }
  }
  handle = dlopen(mylib, RTLD_NOW);
  if (!handle) {
    printf("could not dlopen: %s\n", dlerror());
    return 1;
  }
  return 0;
}

int MPI_Init(int *argc, char ***argv) {
  if (myinit()){
    printf("return early");
    return 1;
  }
  typedef int (*mpiinit)(int *, char ***);
  mpiinit func = (mpiinit)dlsym(handle, "mpi_Init");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }

  MPI_COMM_WORLD = *((MPI_Comm *)dlsym(handle, "mpi_COMM_WORLD"));
  MPI_COMM_NULL = *((MPI_Comm *)dlsym(handle, "mpi_COMM_NULL"));
  MPI_DOUBLE = *((MPI_Datatype *)dlsym(handle, "mpi_DOUBLE"));
  MPI_INT = *((MPI_Datatype *)dlsym(handle, "mpi_INT"));
  MPI_BYTE = *((MPI_Datatype *)dlsym(handle, "mpi_BYTE"));
  MPI_C_BOOL = *((MPI_Datatype *)dlsym(handle, "mpi_C_BOOL"));
  MPI_MAX = *((MPI_Op *)dlsym(handle, "mpi_MAX"));
  MPI_MIN = *((MPI_Op *)dlsym(handle, "mpi_MIN"));
  MPI_SUM = *((MPI_Op *)dlsym(handle, "mpi_SUM"));
  MPI_LOR = *((MPI_Op *)dlsym(handle, "mpi_LOR"));
  MPI_BOR = *((MPI_Op *)dlsym(handle, "mpi_BOR"));
  MPI_REQUEST_NULL = *((MPI_Request *)dlsym(handle, "mpi_REQUEST_NULL"));
  MPI_GROUP_EMPTY = *((MPI_Group *)dlsym(handle, "mpi_GROUP_EMPTY"));
  MPI_SUCCESS = *((int *)dlsym(handle, "mpi_SUCCESS"));
  MPI_UNDEFINED = *((int *)dlsym(handle, "mpi_UNDEFINED"));

  err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(argc, argv);
}


int MPI_Initialized(int *flag) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(int *);
  wrap func = (wrap)dlsym(handle, "mpi_Initialized");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(flag);
}

int MPI_Comm_size(MPI_Comm comm, int *size) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(MPI_Comm , int *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_size");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, size);
}

int MPI_Comm_rank(MPI_Comm comm, int *rank) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(MPI_Comm , int *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_rank");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, rank);
}

double MPI_Wtime() {
  if (myinit()){
    return 1;
  }
  typedef double (*wrap)();
  wrap func = (wrap)dlsym(handle, "mpi_Wtime");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func();
}

int MPI_Finalize() {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)();
  wrap func = (wrap)dlsym(handle, "mpi_Finalize");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func();
}

int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(const void *, void *, int , MPI_Datatype , MPI_Op , MPI_Comm );
  wrap func = (wrap)dlsym(handle, "mpi_Allreduce");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(sendbuf, recvbuf, count, datatype, op, comm);
}

int MPI_Waitany(int count, MPI_Request *array_of_requests, int *indx, MPI_Status * status) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(int , MPI_Request *, int *, MPI_Status * );
  wrap func = (wrap)dlsym(handle, "mpi_Waitany");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, array_of_requests, indx, status);
}

int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(const void *, int , MPI_Datatype , int , int , MPI_Comm );
  wrap func = (wrap)dlsym(handle, "mpi_Send");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, tag, comm);
}

int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Request * request) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(void *, int , MPI_Datatype , int , int , MPI_Comm , MPI_Request * );
  wrap func = (wrap)dlsym(handle, "mpi_Irecv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, source, tag, comm, request);
}

int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status * status) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(void *, int , MPI_Datatype , int , int , MPI_Comm , MPI_Status * );
  wrap func = (wrap)dlsym(handle, "mpi_Recv");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, source, tag, comm, status);
}

int MPI_Comm_free(MPI_Comm comm) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(MPI_Comm );
  wrap func = (wrap)dlsym(handle, "mpi_Comm_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm);
}

int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(MPI_Comm , MPI_Comm *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_dup");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, newcomm);
}

int MPI_Barrier(MPI_Comm comm) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(MPI_Comm );
  wrap func = (wrap)dlsym(handle, "mpi_Barrier");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm);
}

int MPI_Type_vector(int count, int blocklength, int stride, MPI_Datatype oldtype, MPI_Datatype * newtype) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(int , int , int , MPI_Datatype , MPI_Datatype * );
  wrap func = (wrap)dlsym(handle, "mpi_Type_vector");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, blocklength, stride, oldtype, newtype);
}

int MPI_Type_commit(MPI_Datatype * datatype) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype * );
  wrap func = (wrap)dlsym(handle, "mpi_Type_commit");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype);
}

int MPI_Isend(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm, MPI_Request * request) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(const void *, int , MPI_Datatype , int , int , MPI_Comm , MPI_Request * );
  wrap func = (wrap)dlsym(handle, "mpi_Isend");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(buf, count, datatype, dest, tag, comm, request);
}

int MPI_Waitall(int count, MPI_Request* array_of_requests, MPI_Status * array_of_statuses) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(int , MPI_Request* , MPI_Status * );
  wrap func = (wrap)dlsym(handle, "mpi_Waitall");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(count, array_of_requests, array_of_statuses);
}

int MPI_Type_free(MPI_Datatype * datatype) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(MPI_Datatype * );
  wrap func = (wrap)dlsym(handle, "mpi_Type_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(datatype);
}

int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm * newcomm) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(MPI_Comm , int , int , MPI_Comm * );
  wrap func = (wrap)dlsym(handle, "mpi_Comm_split");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, color, key, newcomm);
}

int MPI_Wait(MPI_Request * request, MPI_Status * status) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(MPI_Request * , MPI_Status * );
  wrap func = (wrap)dlsym(handle, "mpi_Wait");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(request, status);
}

int MPI_Group_free(MPI_Group * group) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(MPI_Group * );
  wrap func = (wrap)dlsym(handle, "mpi_Group_free");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group);
}

int MPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group * newgroup) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(MPI_Group , MPI_Group , MPI_Group * );
  wrap func = (wrap)dlsym(handle, "mpi_Group_union");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group1, group2, newgroup);
}

int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm * newcomm) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(MPI_Comm , MPI_Group , MPI_Comm * );
  wrap func = (wrap)dlsym(handle, "mpi_Comm_create");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, group, newcomm);
}

int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group * newgroup) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(MPI_Group , int , int [][3], MPI_Group * );
  wrap func = (wrap)dlsym(handle, "mpi_Group_range_incl");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(group, n, ranges, newgroup);
}

int MPI_Comm_group(MPI_Comm comm, MPI_Group * group) {
  if (myinit()){
    return 1;
  }
  typedef int (*wrap)(MPI_Comm , MPI_Group * );
  wrap func = (wrap)dlsym(handle, "mpi_Comm_group");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, group);
}
