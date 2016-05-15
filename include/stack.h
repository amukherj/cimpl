#ifndef STACK_H
#define STACK_H

#include "node.h"

typedef struct _stack
{
    nodeptr head;

    void (*_destructor)();

    void (*push)(struct _stack *thisptr, void *data);
    nodeptr (*pop)(struct _stack *thisptr);
    int (*is_empty)(const struct _stack *thisptr);
} stack, *stackptr;

stackptr make_stack();
void delete_stack(stackptr stk);

#endif /* STACK_H */
