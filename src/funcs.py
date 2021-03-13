import re

_funcs = (
    ("int", "MPI_Initialized", "int *flag"),
    ("int", "MPI_Comm_size", "MPI_Comm comm", "int *size"),
    ("int", "MPI_Comm_rank", "MPI_Comm comm", "int *rank"),
    ("double", "MPI_Wtime"),
    ("int", "MPI_Finalize"),
)


class Func:
    def __init__(self, fun):
        self.ret = fun[0]
        self.funn = fun[1]
        args = fun[2:]
        argn = [re.findall(r"\w+$", x)[0] for x in args]
        argt = [re.findall(r"(.*[^\w])\w+", x)[0] for x in args]
        self.args = ", ".join(args)
        self.argn = ", ".join(argn)
        self.argt = ", ".join(argt)
        self.funl = "mpi_" + self.funn[4:]


funcs = [Func(f) for f in _funcs]
