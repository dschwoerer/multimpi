#include "mpi.h"
#include "dlfcn.h"
#include "stdio.h"

void *handle = 0;
MPI_Comm MPI_COMM_WORLD;

int MPI_Init(int *argc, char ***argv) {
  if (handle) {
    printf("MPI_Init has been called - ignoring");
    return 0;
  }
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

  typedef int (*mpiinit)(int *, char ***);
  mpiinit func = (mpiinit)dlsym(handle, "mpi_Init");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  MPI_COMM_WORLD = dlsym(handle, "mpi_COMM_WORLD");
  MPI_COMM_WORLD = *((MPI_Comm *)MPI_COMM_WORLD);

  err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(argc, argv);
}

int MPI_Comm_size(MPI_Comm comm, int *size) {
  typedef int (*wrap)(MPI_Comm, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_size");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, size);
}

int MPI_Comm_rank(MPI_Comm comm, int *rank) {
  typedef int (*wrap)(MPI_Comm, int *);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_rank");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(comm, rank);
}

double MPI_Wtime() {
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
  typedef int (*wrap)();
  wrap func = (wrap)dlsym(handle, "mpi_Finalize");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func();
}
