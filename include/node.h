#ifndef NODE_H
#define NODE_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct _node
{
    void *data;
    struct _node *next;

    void (*_destructor)(struct _node *thisptr);
} node, *nodeptr;

nodeptr make_node(void *data, nodeptr next);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* NODE_H */
