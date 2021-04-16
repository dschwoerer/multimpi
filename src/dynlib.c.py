from funcs import funcs, vars, mappings
import re

print(
    """#include "mpi.h"
#include <stdio.h>
"""
)
for a, b in mappings:
    print(
        f'_Static_assert(sizeof({a}) >= sizeof({b}), "Naive mapping for {b} not working!");'
    )

mapdict = {y: x for x, y in mappings}
for a, b in vars:
    bl = "mpi_" + b[4:]
    if a in mapdict:
        print(f"""{mapdict[a]} {bl} = {b};""")
    else:
        print(f"{a} {bl} = {b};")


some = {
    "array_of_requests": "incount",
    "array_of_indices": "*outcount",
    "array_of_statuses": "*outcount",
}
extra_remap = {
    "MPI_Type_get_contents": {
        "array_of_integers": "max_integers",
        "array_of_addresses": "max_addresses",
        "array_of_datatypes": "max_datatypes",
    },
    "MPI_Testsome": some,
    "MPI_Waitsome": some,
}


tomap = [y for x, y in mappings]

print("void multimpi_init(){")
for a, b in vars:
    bl = "mpi_" + b[4:]
    if a in mapdict:
        print(
            f"""
  if (sizeof({a}) != sizeof({mapdict[a]})){{
    char * t = & {bl};
    for (int i=0; i< sizeof({mapdict[a]}) ; ++i) {{
      t[i] = 0;
    }}
    {bl} = {b};
  }}
"""
        )
print("}")

for f in funcs:
    for void, typ in mappings:
        f.args = f.args.replace(typ + " ", void)
    print(
        f"""
{f.ret} {f.funl}({f.args}) {{"""
    )

    remap = []
    realargs = []
    simple = []
    t0s = []
    for typ, arg in zip(f.tl, f.nl):
        t0 = re.match("[a-zA-Z_0-9 ]*", typ)[0].split()[-1]
        t0s.append(t0)
        if t0 not in tomap:
            realargs.append(arg)
            # print(f"//NOT: {t0} {tomap}")
        else:
            realargs.append(arg + "_")
            if arg.startswith("array_of_"):
                remap.append(arg)
                for count in "count", "ndims":
                    if count in f.nl:
                        # print(f"//Remap! {f.name} {typ} {arg}")
                        print(f"  {t0} {arg}_[{count}];")
                        break
                else:
                    # print(f"//PANIC! {f.name} {typ} {arg}")
                    assert f.name in extra_remap
                    print(f"  {t0} {arg}_[{extra_remap[f.name][arg]}];")
            elif "[" in typ:
                realargs[-1] = arg
                print(
                    f'fprintf(stderr, "{f.name} is not implementented in MultiMPI - use MPI directly\\n");'
                )
                print(f"MPI_Abort(MPI_COMM_WORLD, 1);")
                # print(f"#error {typ} {t0} ")
            else:
                simple.append(arg)
                print(f"  {typ} {arg}_ = {arg};")
                # print(f"//allgood: {typ} {arg}")
    # for typ, arg in zip in

    def doremap(remap, count, back):
        print(f"  for (int i=0;i<{count};++i){{")
        for n in remap:
            t0 = t0s[f.nl.index(n)]
            if t0 == "MPI_Status":
                print(
                    f"""
    char * a = {n}{"" if back else "_"} + i;
    char * b = {n}{"_" if back else ""} + i;
    int j=0;
    for (;j<sizeof({t0}); ++j){{
      a[j] = b[j];
    }}
"""
                )
                if back:
                    print(
                        f"""
    for (;j<sizeof({mapdict[t0]}); ++j){{
      a[j] = b[j];
    }}
    """
                    )

            else:
                print(f"    {n}_[i] = {n}[i];")
        print("  }")

    if len(remap):
        if f.name in extra_remap:
            for n in remap:
                count = extra_remap[f.name][n]
                doremap([n], count, False)
        else:
            doremap(remap, count, False)
    realargs = ", ".join(realargs)
    print(f"""  {f.ret}  ret = {f.name}({realargs});""")
    if len(remap):
        if f.name in extra_remap:
            for n in remap:
                count = extra_remap[f.name][n]
                doremap([n], count, True)
        else:
            doremap(remap, count, True)
    for n in simple:
        print(f"  {n} = {n}_;")
    print("  return ret; }")
