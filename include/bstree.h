#ifndef BSTREE_H
#define BSTREE_H

#include "treenode.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct _bstree
{
    treenodeptr root;
    int (*cmp)(const void *lhs, const void *rhs);

    void (*insert)(struct _bstree *thisptr, void *data);
    treenodeptr (*remove)(struct _bstree *thisptr, void *data);
    treenodeptr (*find)(const struct _bstree *thisptr, void *data);

    void (*_destructor)(struct _bstree *thisptr);
} bstree, *bstreeptr;

bstreeptr make_bstree(int (*cmp)(const void *lhs, const void *rhs));

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BSTREE_H */
