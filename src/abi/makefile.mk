CC=mpicc
OBJS=mpi_abi.o mpi_abi_internal.o

libmpi_abi.a: $(OBJS)
	ar rcs libmpi_abi.a $(OBJS)

.c.o:
	$(CC) -o $@ -c $<

install:
	cp libmpi_abi.a $(HOME)/bin
	cp mpi_abi.h $(HOME)/include
	install -m 755 mpicc_abi $(HOME)/bin

clean:
	rm -f $(OBJS) libmpi_abi.a
