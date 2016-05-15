#include "node.h"
#include <stdlib.h>

static void node_destructor(nodeptr thisptr);

nodeptr make_node(void *data, nodeptr next)
{
    nodeptr result = malloc(sizeof(node));

    result->data = data;
    result->next = next;

    result->_destructor = &node_destructor;

    return result;
}

static void node_destructor(nodeptr thisptr)
{
    free(thisptr);
}
