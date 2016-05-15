#include "stack.h"
#include <stdlib.h>

static void push(stackptr stack, void *data);
static nodeptr pop(stackptr thisptr);
static int is_empty(const stackptr thisptr);
static void stack_destructor(stackptr thisptr);

stackptr make_stack()
{
    stackptr result = malloc(sizeof(stack));

    result->head = NULL;
    result->push = &push;
    result->pop = &pop;
    result->is_empty = &is_empty;
    result->_destructor = &stack_destructor;

    return result;
}

static void push(stackptr stack, void *data)
{
    nodeptr new_head = make_node(data, stack->head);
    stack->head = new_head;
}

static nodeptr pop(stackptr thisptr)
{
    if (!thisptr->head) {
        return NULL;
    }

    nodeptr result = thisptr->head;
    thisptr->head = result->next;

    return result;
}

static int is_empty(const stackptr thisptr)
{
    return (!thisptr->head);
}

static void stack_destructor(stackptr thisptr)
{
    nodeptr head = thisptr->head;
    thisptr->head = NULL;

    while (head) {
        nodeptr tmp = head;
        head = head->next;
        tmp->_destructor(head);
    }
}

