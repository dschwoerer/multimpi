test: test/hello lib/openmpi.so
	test/hello

bins=mpicc mpic++

.PHONY: test dirs

dirs:
	$(MAKE) -C src src
	$(MAKE) -C include include

test/hello:test/hello_mpi.o lib/libmpi.a $(bins:%=bin/%)
	bin/mpicc -o $@ $<

lib/libmpi.a: src/staticlib.o
	test -d lib || mkdir lib
	ar cruU $@ $<

%.o: %.c $(bins:%=bin/%) dirs
	bin/mpicc -c $< -fpic -o $@

lib/openmpi.so: build.so.sh src/dynlib.c
	sh $<

clean::
	rm src/*.o
	rm lib/*.so
	rm lib/*.a
	rm test/hello
	rm bin/mpic++
	rm bin/mpicc

%: %.in
	sh $< > $@.tmp
	mv $@.tmp $@
	chmod +x $@

