test: hello openmpi.so
	./hello

hello:hello_mpi.o static.a
	cc -o $@ $< static.a -ldl

static.a: staticlib.o
	ar cruU $@ $<

%.o: %.c
	cc -c $< -fpic -o $@

openmpi.so: build.so.sh dynlib.c
	sh $<

clean::
	rm *.o
	rm *.so
	rm static.a
	rm hello
