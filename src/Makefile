
CFLAGS=-g -Wall -I../include
ARFLAGS=rv

all: libcimpl.a

clean:
	rm -rf *.o *.a

libcimpl.a: slist.o node.o stack.o
	$(AR) $(ARFLAGS) $@ $^

