import re


_fun3 = ""
with open("../allfuncs") as f:
    for l in f:
        if l.startswith("#"):
            continue
        _fun3 += l

_funcs = []
for f in _fun3.split("\n\n"):
    if f == "":
        continue
    f = f.split("(")
    fs = f[0].split()
    fs += f[1].split(",")
    fs = [f.strip().strip(")").strip() for f in fs]
    if len(fs) == 3 and fs[-1] == "void":
        fs = fs[:2]
    _funcs.append(fs)


class Func:
    def __init__(self, fun):
        self.ret = fun[0]
        self.funn = fun[1]
        args = fun[2:]
        try:
            argn = [re.findall(r"[a-zA-Z_][a-zA-Z0-9_]*", x)[-1] for x in args]
        except:
            print(fun)
            print(args)
            raise
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
    ("void *", "MPI_File"),
    ("void *", "MPI_Win"),
    ("void *", "MPI_Aint"),
    ("void *", "MPI_Offset"),
    ("void *", "MPI_Info"),
    ("void *", "MPI_Errhandler"),
    ("void *", "MPIO_Request"),
    ("void *", "MPI_Message"),
    ("void *", "MPI_Delete_function"),
    ("void *", "MPI_User_function"),
    ("void *", "MPI_Comm_copy_attr_function"),
    ("void *", "MPI_Comm_delete_attr_function"),
    ("void *", "MPI_Comm_errhandler_function"),
    ("void *", "MPI_Copy_function"),
    ("void *", "MPI_Count"),
    ("void *", "MPI_Datarep_conversion_function"),
    ("void *", "MPI_Datarep_extent_function"),
    ("void *", "MPI_File_errhandler_function"),
    ("void *", "MPI_Fint"),
    ("void *", "MPI_Grequest_cancel_function"),
    ("void *", "MPI_Grequest_free_function"),
    ("void *", "MPI_Grequest_query_function"),
    ("void *", "MPI_Handler_function"),
    ("void *", "MPI_T_cvar_handle"),
    ("void *", "MPI_T_enum"),
    ("void *", "MPI_T_pvar_handle"),
    ("void *", "MPI_T_pvar_session"),
    ("void *", "MPI_Type_copy_attr_function"),
    ("void *", "MPI_Type_delete_attr_function"),
    ("void *", "MPI_Win_copy_attr_function"),
    ("void *", "MPI_Win_delete_attr_function"),
    ("void *", "MPI_Win_errhandler_function"),
)
