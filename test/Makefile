
CFLAGS=-g -Wall -I../include
ARFLAGS=rv

VPATH=../include:../src

all: tests

clean:
	rm -rf *.o test_node test_stack test_slist

tests: test_node test_stack test_slist

test_node: test_node.o libcimpl.a

test_stack: test_stack.o libcimpl.a

test_slist: test_slist.o libcimpl.a
