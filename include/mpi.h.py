from funcs import funcs, vars, mappings
print("""#ifdef __cplusplus
extern "C" {
#endif""")

for a,b in mappings:
    print(f"typedef {a} {b};")
for a,b in vars:
    print(f"extern {a} {b};")

print("""
int MPI_Init(int *argc, char ***argv);""")
for f in funcs:
    print(f"""
{f.ret} {f.funn}({f.args});""")
print("""
#ifdef __cplusplus
}
#endif
""")
