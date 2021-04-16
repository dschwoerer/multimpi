test: test/hello lib/openmpi.so
	module load mpi && LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:lib/ test/hello

bins=mpicc mpic++

PREFIX ?= /opt/local/multmpi/
PWD:=$(shell pwd)

.PHONY: test dirs src include check install
check:test

src:
	$(MAKE) -C $@ $@
include:
	$(MAKE) -C $@ $@


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

lib/openmpi.so: build.so.2.sh src/dynlib.c
	sh $<

install:
	mkdir -p $(PREFIX)/lib
	mkdir -p $(PREFIX)/bin
	mkdir -p $(PREFIX)/include
	cd $(PREFIX) ; for bin in $(bins) ; do sh $(PWD)/bin/$$bin.in > bin/$$bin; chmod +x bin/$$bin ; done
	install lib/* $(PREFIX)/lib/
	install include/*.h $(PREFIX)/include/

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

