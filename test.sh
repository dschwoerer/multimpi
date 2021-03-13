#!/bin/bash

set -e


module purge
module load mpi/openmpi-x86_64
./hello
module purge
module load mpi/mpich-x86_64
./hello

