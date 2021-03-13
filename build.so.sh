#!/bin/bash
set -ex
module purge
module load mpi/openmpi-x86_64
mpicc -c dynlib.c -fpic -o dynlib.o
mpicc -shared -o openmpi.so dynlib.o
module purge
module load mpi/mpich-x86_64
mpicc -c dynlib.c -fpic -o dynlib.o
mpicc -shared -o mpich.so dynlib.o

