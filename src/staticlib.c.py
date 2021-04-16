#!/usr/bin/env python3

from funcs import funcs, vars
from libs import libs

print(
    r"""#include "mpi.h"
#include "dlfcn.h"
#include "stdio.h"

void *handle = 0;
"""
)
for a, b in vars:
    print(f"{a} {b};")

print(
    r"""
int multimpi_static_init(){
  if (handle)
    return 0;
  const char * mylib;
"""
)
for so, my in libs:
    print(
        fr"""
  handle = dlopen("{so}", RTLD_NOW);
  if (handle){{
    dlclose(handle);
    mylib= "multimpi_{my}.so";
  }} else {{
"""
    )
print(
    r"""
      printf("could not find a suitable mpilibrary. Ensure LD_LIBRARY_PATH is correct\n");
      return 1;
"""
)
print("}" * len(libs))
print(
    r"""
  handle = dlopen(mylib, RTLD_NOW);
  if (!handle) {
    printf("could not dlopen: %s\n", dlerror());
    return 1;
  }
  typedef void (*dyn_init)(void);
  dyn_init func = (dyn_init)dlsym(handle, "multimpi_init");
  func();
  return 0;
}

int multimpi_MPI_Init(int *argc, char ***argv) {
  if (multimpi_static_init()){
    printf("return early\n");
    return 1;
  }
  typedef int (*mpiinit)(int *, char ***);
  mpiinit func = (mpiinit)dlsym(handle, "mpi_Init");
  const char *err = dlerror();
  if (err) {
    printf("could not dlsym: %s\n", err);
    return 1;
  }
"""
)
for a, b in vars:
    assert b[:4] == "MPI_"
    bl = "mpi_" + b[4:]
    print(f'  {b} = *(({a} *)dlsym(handle, "{bl}"));')
print(
    r"""
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
    if fun.name == "MPI_Init":
        continue
    errrets = {
        "int": 1,
        "void *": "NULL",
        "MPI_Fint": "NULL",
        "MPI_File": "NULL",
        "double": 0,
    }
    try:
        errret = errrets[fun.ret]
    except:
        errret = 0
    print(
        f"""
{fun.ret} multimpi_{fun.name}({fun.args}) {{
  if (multimpi_static_init()){{
    return {errret};
  }}
  typedef {fun.ret} (*wrap)({fun.argt});
  wrap func = (wrap)dlsym(handle, "{fun.funl}");
  const char *err = dlerror();
  if (err) {{
    printf("could not dlsym: %s\\n", err);
    return {errret};
  }}
  return func({fun.argn});
}}"""
    )
