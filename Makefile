test: hello openmpi.so
	./hello

hello:hello_mpi.o static.a
	mpicc -o $@ $< static.a -ldl

static.a: staticlib.o
	ar cruU $@ $<

%.o: %.c
	mpicc -c $< -fpic -o $@

dynlib.o: dynlib.c
	mpicc -c $< -fpic -o $@
openmpi.so: dynlib.o
	mpicc -shared -o $@ $<

