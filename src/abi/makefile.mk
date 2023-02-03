CC=mpicc
OBJS=mpi_abi.o mpi_abi_internal.o

libmpi_abi.a: $(OBJS)
	$(CC) -shared -o libmpi_abi.so $(OBJS)

.c.o:
	$(CC) -fPIC -o $@ -c $<

install: libmpi_abi.a
	cp libmpi_abi.so $(HOME)/bin
	cp mpi_abi.h $(HOME)/include
	install -m 755 mpicc_abi $(HOME)/bin

clean:
	rm -f $(OBJS) libmpi_abi.so
