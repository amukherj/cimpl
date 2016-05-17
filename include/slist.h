#ifndef LIST_H
#define LIST_H

#include "node.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct _slist
{
    nodeptr head;
    nodeptr end;

    void (*push_back)(struct _slist *thisptr, void *data);
    nodeptr (*pop_back)(struct _slist *thisptr);
    nodeptr (*pop_front)(struct _slist *thisptr);
    nodeptr (*front)(struct _slist *thisptr);
    int (*is_empty)(const struct _slist *thisptr);

    void (*_destructor)(struct _slist *thisptr);
} slist, *slistptr;

slistptr make_slist();

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LIST_H */
