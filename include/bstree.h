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
    int (*is_empty)(const struct _bstree *thisptr);

    void (*traverse_inorder)(const struct _bstree *thisptr,
                                void (*action)(const treenode*));
    void (*traverse_preorder)(const struct _bstree *thisptr,
                                void (*action)(const treenode*));
    void (*traverse_postorder)(const struct _bstree *thisptr,
                                void (*action)(const treenode*));
    void (*traverse_levelorder)(const struct _bstree *thisptr,
                                void (*action)(const treenode*));

    void (*_destructor)(struct _bstree *thisptr);
} bstree, *bstreeptr;

bstreeptr make_bstree(int (*cmp)(const void *lhs, const void *rhs));

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BSTREE_H */
