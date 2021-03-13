#include "staticlib.h"
#include "dlfcn.h"
#include "stdio.h"

void * handle= 0;

int mpi_Init(int * argc, char *** argv){
  if (handle){
    printf("MPI_Init has been called - ignoring");
    return 0;
  }
    
  
  void* handle = dlopen("./openmpi.so",RTLD_NOW);
  if(!handle)
  {
    printf("could not dlopen: %s\n",dlerror());
    return 1;
  }

  typedef int(*mpiinit)(int*,char***);
  mpiinit func =(mpiinit) dlsym(handle,"mpi_Init");
  const char* err = dlerror();
  if(err)
    {
      printf("could not dlsym: %s\n",err);
      return 1;
    }
  return func( argc, argv);
}

int mpi_Comm_size( MPI_Comm comm, int *size ) {
  typedef int(*wrap)(MPI_Comm,int*);
  wrap func = (wrap)dlsym(handle, "mpi_Comm_size");
  const char* err = dlerror();
  if(err)
    {
      printf("could not dlsym: %s\n",err);
      return 1;
    }
  return func(comm, size);
}
