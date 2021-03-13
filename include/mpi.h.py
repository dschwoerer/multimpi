from funcs import funcs

print("""typedef void *MPI_Comm;
typedef double MPI_DOUBLE;
typedef int MPI_INT;
extern int MPI_SUCCESS;

extern MPI_Comm MPI_COMM_WORLD;
extern MPI_Comm MPI_COMM_NULL;

int MPI_Init(int *argc, char ***argv);""")
for f in funcs:
    print(f"""
{f.ret} {f.funn}({f.args});""")

