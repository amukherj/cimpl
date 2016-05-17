#include "bstree.h"
#include <stdlib.h>

static void insert(bstree *thisptr, void *data);
static treenodeptr remove(bstree *thisptr, void *data);
static treenodeptr find(const bstree *thisptr, void *data);
static void bstree_destructor(bstree *thisptr);

bstreeptr make_bstree(int (*cmp)(const void *lhs, const void *rhs))
{
    bstreeptr result = malloc(sizeof(bstree));
    result->root = NULL;
    result->cmp = cmp;

    result->insert = &insert;
    result->remove = &remove;
    result->find = &find;
    result->_destructor = &bstree_destructor;

    return result;
}

static void insert(struct _bstree *thisptr, void *data)
{
    if (!thisptr->root) {
        thisptr->root = make_treenode(data, NULL, NULL);
        return;
    }

    treenodeptr result = thisptr->root;
    int direction = thisptr->cmp(result->data, data);

    while (direction) {
        treenodeptr new_result =
            result->children[ (direction < 0) ? 0 : 1 ];
        if (!new_result) {
            result->children[ (direction < 0) ? 0 : 1 ]
                = make_treenode(data, NULL, NULL);
            direction = 0;
        } else {
            result = new_result;
            direction = thisptr->cmp(result->data, data);
        }
    }
}

static treenodeptr pluck_smallest_successor(bstree *thisptr,
                                           treenodeptr current)
{
    treenodeptr parent = current;
    treenodeptr result = current->children[1];

    while (result && result->children[0]) {
        parent = result;
        result = result->children[0];
    }

    parent->children[0] = result->children[1];
    result->children[0] = result->children[1] = NULL;

    return result;
}

static treenodeptr remove(bstree *thisptr, void *data)
{
    treenodeptr parent = NULL;
    treenodeptr current = thisptr->root;
    int direction = -1;
    int old_direction = -1;

    while (current && direction) {
        old_direction = direction;
        direction = thisptr->cmp(current->data, data);

        if (direction != 0) {
            parent = current;
            current = parent->children[ (direction < 0) ? 0 : 1 ]; 
        }
    }

    if (!current) {
        return current;
    }

    treenodeptr new_current = NULL;
    if (!current->children[0]) {
        new_current = current->children[1];
    } else if (!current->children[1]) {
        new_current = current->children[0];
    } else {
        new_current = pluck_smallest_successor(thisptr, current);
        new_current->children[0] = current->children[0];
        new_current->children[1] = current->children[1];
    }

    current->children[0] = current->children[1] = NULL;
    if (parent) {
        parent->children[ (old_direction < 0) ? 0 : 1 ] = new_current;
    } else {
        thisptr->root = new_current;
    }

    return current;
}

static treenodeptr find(const struct _bstree *thisptr, void *data)
{
    treenodeptr result = thisptr->root;
    int direction = thisptr->cmp(result->data, data);

    while (result && direction != 0) {
        if (direction < 0) {
            result = result->children[0];
        } else {
            result = result->children[1];
        }
        
        if (result) {
            direction = thisptr->cmp(result->data, data);
        }
    }

    return result;
}

static void subtree_destructor(treenodeptr stnode)
{
    if (!stnode) {
        return;
    }

    if (stnode->children[0]) {
        subtree_destructor(stnode->children[0]);
    }

    if (stnode->children[1]) {
        subtree_destructor(stnode->children[1]);
    }

    stnode->_destructor(stnode);
}

static void bstree_destructor(bstreeptr thisptr)
{
    subtree_destructor(thisptr->root);
}
