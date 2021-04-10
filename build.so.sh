#!/bin/bash
set -ex
module purge
module load mpi/openmpi-x86_64
mpicc -c src/dynlib.c -fpic -o src/dynlib.o -w
mpicc -shared -o lib/openmpi.so src/dynlib.o
module purge
module load mpi/mpich-x86_64
mpicc -c src/dynlib.c -fpic -o src/dynlib.o -w
mpicc -shared -o lib/mpich.so src/dynlib.o

