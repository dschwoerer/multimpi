from funcs import funcs, vars

print(
    """#include "mpi.h"
#include <stdio.h>
""")

for a,b in vars:
    bl = "mpi_"+b[4:]
    print(f"{a} {bl} = {b};")

for f in funcs:
    f.args = f.args.replace("MPI_Comm ","void *")
    print(
        f"""
{f.ret} {f.funl}({f.args}) {{ return {f.funn}({f.argn}); }}"""
    )
