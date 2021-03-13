#!/usr/bin/env python3

from funcs import funcs

print(
    r"""#include "mpi.h"
#include "dlfcn.h"
#include "stdio.h"

void *handle = 0;
MPI_Comm MPI_COMM_WORLD;
MPI_Comm MPI_COMM_NULL;
int MPI_SUCCESS = 0;

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

  err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
  return func(argc, argv);
}
"""
)

for fun in funcs:
    print(
        f"""
{fun.ret} {fun.funn}({fun.args}) {{
  if (myinit()){{
    return 1;
  }}
  typedef {fun.ret} (*wrap)({fun.argt});
  wrap func = (wrap)dlsym(handle, "{fun.funl}");
  const char *err = dlerror();
  if (err) {{
    printf("could not dlsym: %s\\n", err);
    return 1;
  }}
  return func({fun.argn});
}}"""
    )
