
CFLAGS=-g -Wall -I../include -std=c99 # -fPIC
# LDFLAGS=../lib/libcimpl.a # -fPIC

VPATH=../include:../src:../lib

all: tests

clean:
	rm -rf *.o ../bintest/test_node ../bintest/test_stack ../bintest/test_slist

tests: ../bintest/test_stack ../bintest/test_slist ../bintest/test_node ../bintest/test_bstree

../bintest/test_node: test_node.o ../lib/libcimpl.a
	$(CC) -o $@ $^ 

../bintest/test_stack: test_stack.o ../lib/libcimpl.a
	$(CC) -o $@ $^ 

../bintest/test_slist: test_slist.o ../lib/libcimpl.a
	$(CC) -o $@ $^ 

../bintest/test_bstree: test_bstree.o ../lib/libcimpl.a
	$(CC) -o $@ $^ 

