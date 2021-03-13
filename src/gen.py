#!/usr/bin/env python3
import re

from funcs import funcs

print(
    r"""#include "mpi.h"
#include "dlfcn.h"
#include "stdio.h"

void *handle = 0;
MPI_Comm MPI_COMM_WORLD;

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
}

int MPI_Init(int *argc, char ***argv) {
  if (myinit()){
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
"""
)

for fun in funcs:
    ret = fun[0]
    funn = fun[1]
    args = fun[2:]
    argn = [re.findall(r"\w+$", x)[0] for x in args]
    argt = [re.findall(r"(.*[^\w])\w+", x)[0] for x in args]
    args = ", ".join(args)
    argn = ", ".join(argn)
    argt = ", ".join(argt)
    funl = "mpi_" + funn[4:]
    print(
        f"""
{ret} {funn}({args}) {{
  if (myinit()){{
    return 1;
  }}
  typedef {ret} (*wrap)({argt});
  wrap func = (wrap)dlsym(handle, "{funl}");
  const char *err = dlerror();
  if (err) {{
    printf("could not dlsym: %s\\n", err);
    return 1;
  }}
  return func({argn});
}}
"""
    )
