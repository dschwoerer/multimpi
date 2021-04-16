from funcs import funcs, vars, mappings

print(
    """#pragma once
#ifdef __cplusplus
extern "C" {
#endif"""
)

for a, b in mappings:
    print(f"typedef {a} {b};")
for a, b in vars:
    print(f"extern {a} {b};")


for f in funcs:
    print(
        f"""
{f.ret} multimpi_{f.name}({f.args});
static inline {f.ret} {f.name}({f.args}) {{ return multimpi_{f.name}({f.argn}); }}
"""
    )
print(
    """
#ifdef __cplusplus
}
#endif
"""
)
