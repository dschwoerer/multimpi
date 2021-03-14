src: staticlib.c dynlib.c

include: mpi.h

%.c: %.c.py funcs.py ../allfuncs
	python3 $< > $@.tmp
	mv $@.tmp $@

%.h: %.h.py funcs.py ../allfuncs
	python3 $< > $@.tmp
	mv $@.tmp $@
