#!/bin/bash
set -ex
PATH0="$PATH"
LD0="$LD_LIBRARY_PATH"
module purge || :
for mod in $(python3 src/libs.py) ; do
    export PATH="$dir0/$mod/bin:$PATH0"
    export LD_LIBRARY_PATH="$dir0/$mod/lib:$LD0"
    mpicc -c src/dynlib.c -fpic -o src/dynlib.o -w
    mpicc -shared -o lib/multimpi_$mod.so src/dynlib.o
done

