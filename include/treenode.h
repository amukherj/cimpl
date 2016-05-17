#ifndef TREENODE_H
#define TREENODE_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct _treenode
{
    void *data;
    struct _treenode *children[2];

    void (*_destructor)(struct _treenode *thisptr);
} treenode, *treenodeptr;

treenodeptr make_treenode(void *data, treenodeptr left, treenodeptr right);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* TREENODE_H */
