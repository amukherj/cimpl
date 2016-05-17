#include "treenode.h"
#include <stdlib.h>

static void treenode_destructor(treenodeptr thisptr);

treenodeptr make_treenode(void *data, treenodeptr left, treenodeptr right)
{
    treenodeptr result = malloc(sizeof(treenode));
    result->data = data;
    result->children[0] = left;
    result->children[1] = right;

    result->_destructor = &treenode_destructor;

    return result;
}

static void treenode_destructor(treenodeptr thisptr)
{
    free(thisptr);
}

