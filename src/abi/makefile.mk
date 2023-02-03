DESTDIR ?= $(HOME)

CC=mpicc
OBJS=mpi_abi.o mpi_abi_internal.o

libmpi_abi.a: $(OBJS)
	$(CC) -shared -o libmpi_abi.so $(OBJS)

.c.o:
	$(CC) -fPIC -o $@ -c $<

install: libmpi_abi.a
	cp libmpi_abi.so $(DESTDIR)/bin
	cp mpi_abi.h $(DESTDIR)/include
	sed -e "s|__INSTALL_DESTDIR__|$(DESTDIR)|" mpicc_abi.in > mpicc_abi
	install -m 755 mpicc_abi $(DESTDIR)/bin

clean:
	rm -f $(OBJS) libmpi_abi.so
