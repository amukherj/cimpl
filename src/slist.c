#include "slist.h"
#include <stdlib.h>

static void push_back(struct _slist *thisptr, void *data);
static nodeptr pop_back(struct _slist *thisptr);
static nodeptr pop_front(struct _slist *thisptr);
static nodeptr front(struct _slist *thisptr);
static int is_empty(const struct _slist *thisptr);
static void list_destructor(struct _slist *thisptr);


slistptr make_slist()
{
    slistptr result = malloc(sizeof(slist));
    result->head = result->end = make_node(NULL, NULL);

    result->push_back = &push_back;
    result->pop_back = &pop_back;
    result->is_empty = &is_empty;
    result->pop_front = &pop_front;
    result->front = &front;
    result->_destructor = &list_destructor;

    return result;
}


static void push_back(struct _slist *thisptr, void *data)
{
    nodeptr new_end = make_node(data, NULL);
    thisptr->end->next = new_end;
    thisptr->end = new_end;
}


static nodeptr pop_back(struct _slist *thisptr)
{
    if (thisptr->is_empty(thisptr)) {
        return NULL;
    }

    node *ptr = thisptr->head;
    while (ptr->next != thisptr->end) {
        ptr = ptr->next;
    }

    thisptr->end = ptr;
    ptr = ptr->next;
    thisptr->end->next = NULL;

    return ptr;
}

static nodeptr pop_front(struct _slist *thisptr)
{
    if (thisptr->is_empty(thisptr)) {
        return NULL;
    }

    node *ptr = thisptr->head->next;
    thisptr->head->next = ptr->next;
    ptr->next = NULL;

    if (thisptr->end == ptr) {
        thisptr->end = thisptr->head;
    }

    return ptr;
}

static nodeptr front(struct _slist *thisptr)
{
    if (thisptr->is_empty(thisptr)) {
        return NULL;
    }

    return thisptr->head->next;
}

static int is_empty(const struct _slist *thisptr)
{
    return (thisptr->head == thisptr->end);
}


static void list_destructor(struct _slist *thisptr)
{
    while (!thisptr->is_empty(thisptr)) {
        nodeptr popped = thisptr->pop_front(thisptr);
        popped->_destructor(popped);
    }

    thisptr->head->_destructor(thisptr->head);
    thisptr->head = thisptr->end = NULL;
}

