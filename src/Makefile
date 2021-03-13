src: staticlib.c dynlib.c

include: mpi.h

%.c: %.c.py funcs.py
	python3 $< > $@.tmp
	mv $@.tmp $@

%.h: %.h.py funcs.py
	python3 $< > $@.tmp
	mv $@.tmp $@
