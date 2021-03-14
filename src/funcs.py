import re

_funcs = [
    ("int", "MPI_Initialized", "int *flag"),
    ("int", "MPI_Comm_size", "MPI_Comm comm", "int *size"),
    ("int", "MPI_Comm_rank", "MPI_Comm comm", "int *rank"),
    ("double", "MPI_Wtime"),
    ("int", "MPI_Finalize"),
    (
        "int",
        "MPI_Allreduce",
        "const void *sendbuf",
        "void *recvbuf",
        "int count",
        "MPI_Datatype datatype",
        "MPI_Op op",
        "MPI_Comm comm",
    ),
    (
        "int",
        "MPI_Waitany",
        "int count",
        "MPI_Request *array_of_requests",
        "int *indx",
        "MPI_Status * status",
    ),
    (
        "int",
        "MPI_Send",
        "const void *buf",
        "int count",
        "MPI_Datatype datatype",
        "int dest",
        "int tag",
        "MPI_Comm comm",
    ),
    (
        "int",
        "MPI_Irecv",
        "void *buf",
        "int count",
        "MPI_Datatype datatype",
        "int source",
        "int tag",
        "MPI_Comm comm",
        "MPI_Request * request",
    ),
    (
        "int",
        "MPI_Recv",
        "void *buf",
        "int count",
        "MPI_Datatype datatype",
        "int source",
        "int tag",
        "MPI_Comm comm",
        "MPI_Status * status",
    ),
    ("int", "MPI_Comm_free", "MPI_Comm comm"),
    ("int", "MPI_Comm_dup", "MPI_Comm comm", "MPI_Comm *newcomm"),
    ("int", "MPI_Barrier", "MPI_Comm comm"),
    (
        "int",
        "MPI_Type_vector",
        "int count",
        "int blocklength",
        "int stride",
        "MPI_Datatype oldtype",
        "MPI_Datatype * newtype",
    ),
    ("int", "MPI_Type_commit", "MPI_Datatype * datatype"),
    (
        "int",
        "MPI_Isend",
        "const void *buf",
        "int count",
        "MPI_Datatype datatype",
        "int dest",
        "int tag",
        "MPI_Comm comm",
        "MPI_Request * request",
    ),
    (
        "int",
        "MPI_Waitall",
        "int count",
        "MPI_Request* array_of_requests",
        "MPI_Status * array_of_statuses",
    ),
    ("int", "MPI_Type_free", "MPI_Datatype * datatype"),
    (
        "int",
        "MPI_Comm_split",
        "MPI_Comm comm",
        "int color",
        "int key",
        "MPI_Comm * newcomm",
    ),
]

_fun2 = """
int MPI_Wait(MPI_Request * request, MPI_Status * status)
int MPI_Group_free(MPI_Group * group)
int MPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group * newgroup)
int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm * newcomm)
int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3], MPI_Group * newgroup)
int MPI_Comm_group(MPI_Comm comm, MPI_Group * group)
"""
for f in _fun2.split("\n"):
    if f == "":
        continue
    f = f.split("(")
    fs = f[0].split()
    fs += f[1].split(",")
    fs = [f.strip().strip(")") for f in fs]
    _funcs.append(fs)


class Func:
    def __init__(self, fun):
        self.ret = fun[0]
        self.funn = fun[1]
        args = fun[2:]
        argn = [re.findall(r"[a-zA-Z_][a-zA-Z0-9_]*", x)[-1] for x in args]
        # print(argn)
        # argt = [re.findall(r"(.*[^\w])\w+", x)[0] for x in args]
        argt = [re.sub(fr"([^\w]){y}", r"\1", x) for x, y in zip(args, argn)]
        self.args = ", ".join(args)
        self.argn = ", ".join(argn)
        self.argt = ", ".join(argt)
        self.funl = "mpi_" + self.funn[4:]


funcs = [Func(f) for f in _funcs]

vars = (
    ("MPI_Comm", "MPI_COMM_WORLD"),
    ("MPI_Comm", "MPI_COMM_NULL"),
    ("MPI_Datatype", "MPI_DOUBLE"),
    ("MPI_Datatype", "MPI_INT"),
    ("MPI_Datatype", "MPI_BYTE"),
    ("MPI_Datatype", "MPI_C_BOOL"),
    ("MPI_Op", "MPI_MAX"),
    ("MPI_Op", "MPI_MIN"),
    ("MPI_Op", "MPI_SUM"),
    ("MPI_Op", "MPI_LOR"),
    ("MPI_Op", "MPI_BOR"),
    ("MPI_Request", "MPI_REQUEST_NULL"),
    ("MPI_Group", "MPI_GROUP_EMPTY"),
    ("int", "MPI_SUCCESS"),
    ("int", "MPI_UNDEFINED"),
)

mappings = (
    ("void *", "MPI_Comm"),
    ("void *", "MPI_Datatype"),
    ("void *", "MPI_Op"),
    ("void *", "MPI_Request"),
    ("void *", "MPI_Status"),
    ("void *", "MPI_Group"),
)
