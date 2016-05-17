
CFLAGS=-g -Wall -I../include # -fPIC
ARFLAGS=rvs

all: ../lib/libcimpl.a

clean:
	rm -rf *.o ../lib/*.a

../lib/libcimpl.a: slist.o node.o stack.o treenode.o bstree.o
	mkdir -p ../lib
	$(AR) $(ARFLAGS) $@ $^

