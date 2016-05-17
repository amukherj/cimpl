#include "treenode.h"
#include "slist.h"
#include <stdlib.h>

static void traverse_inorder(const treenode *thisptr, void (*action)(const treenode*));
static void traverse_preorder(const treenode *thisptr, void (*action)(const treenode*));
static void traverse_postorder(const treenode *thisptr, void (*action)(const treenode*));
static void traverse_levelorder(const treenode *thisptr, void (*action)(const treenode*));

static void treenode_destructor(treenodeptr thisptr);

treenodeptr make_treenode(void *data, treenodeptr left, treenodeptr right)
{
    treenodeptr result = malloc(sizeof(treenode));
    result->data = data;
    result->children[0] = left;
    result->children[1] = right;

    result->traverse_inorder = &traverse_inorder;
    result->traverse_preorder = &traverse_preorder;
    result->traverse_postorder = &traverse_postorder;
    result->traverse_levelorder = &traverse_levelorder;

    result->_destructor = &treenode_destructor;

    return result;
}

static void traverse_inorder(const treenode *thisptr,
                            void (*action)(const treenode*))
{
    if (!thisptr) {
        action(thisptr);
        return;
    }

    traverse_inorder(thisptr->children[0], action);
    action(thisptr);
    traverse_inorder(thisptr->children[1], action);
}

static void traverse_preorder(const treenode *thisptr,
                            void (*action)(const treenode*))
{
    if (!thisptr) {
        action(thisptr);
        return;
    }

    action(thisptr);
    traverse_preorder(thisptr->children[0], action);
    traverse_preorder(thisptr->children[1], action);
}

static void traverse_postorder(const treenode *thisptr,
                            void (*action)(const treenode*))
{
    if (!thisptr) {
        action(thisptr);
        return;
    }

    traverse_postorder(thisptr->children[0], action);
    traverse_postorder(thisptr->children[1], action);
    action(thisptr);
}

static void traverse_levelorder(const treenode *thisptr,
                            void (*action)(const treenode*))
{
    slistptr queue = make_slist();
    queue->push_back(queue, (treenode*)thisptr);

    while (!queue->is_empty(queue)) {
        node *next = queue->pop_front(queue);
        const treenode *next_node = (const treenode*)(next->data);
        action(next_node);

        if (next_node->children[0]) {
            queue->push_back(queue, next_node->children[0]);
        }

        if (next_node->children[1]) {
            queue->push_back(queue, next_node->children[1]);
        }
    }
}

static void treenode_destructor(treenodeptr thisptr)
{
    free(thisptr);
}

