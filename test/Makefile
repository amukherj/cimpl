
CFLAGS=-g -Wall -I../include # -fPIC
LDFLAGS=../lib/libcimpl.a # -fPIC

VPATH=../include:../src:../lib

all: tests

clean:
	rm -rf *.o ../bintest/test_node ../bintest/test_stack ../bintest/test_slist

tests: ../bintest/test_stack ../bintest/test_slist ../bintest/test_node
	mkdir -p ../bintest

../bintest/test_node: test_node.o ../lib/libcimpl.a

../bintest/test_stack: test_stack.o ../lib/libcimpl.a

../bintest/test_slist: test_slist.o ../lib/libcimpl.a
