#include "node.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>

static void test_make_node()
{
    void *data = (void*)10;
    node next;

    nodeptr ptr = make_node(data, &next);

    IS_TRUE(ptr->data == data);
    IS_TRUE(ptr->next == &next);
}

int main()
{
    test_make_node();

    return 0;
}
