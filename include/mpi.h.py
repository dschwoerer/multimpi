from funcs import funcs, vars, mappings

print(
    """#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#define MPI_MAX_ERROR_STRING 1024
"""
)

for a, b in mappings:
    print(f"typedef {a} {b};")
for a, b in vars:
    print(f"extern {a} {b};")


for f in funcs:
    print(
        f"""
{f.ret} {f.name}({f.args});
"""
    )
print(
    """
#ifdef __cplusplus
}
#endif
"""
)
