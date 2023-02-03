This is implementation of shim layer to work with proposed new MPI ABI.

Reference: https://github.com/mpiwg-abi

USAGE:
    $ make -f makefile.mk
    $ DESTDIR=[path/to/mpich] make -f makefile.mk install

    Assume DESTDIR is in path -
    $ mpicc_abi -o test test
