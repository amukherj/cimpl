#ifndef TREENODE_H
#define TREENODE_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct _treenode
{
    void *data;
    struct _treenode *children[2];

    void (*traverse_inorder)(const struct _treenode *thisptr, void (action)(const struct _treenode*));
    void (*traverse_preorder)(const struct _treenode *thisptr, void (action)(const struct _treenode*));
    void (*traverse_postorder)(const struct _treenode *thisptr, void (action)(const struct _treenode*));
    void (*traverse_levelorder)(const struct _treenode *thisptr, void (action)(const struct _treenode*));

    void (*_destructor)(struct _treenode *thisptr);
} treenode, *treenodeptr;

treenodeptr make_treenode(void *data, treenodeptr left, treenodeptr right);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* TREENODE_H */
