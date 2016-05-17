#include "test.h"
#include "bstree.h"
#include "slist.h"
#include <limits.h>

static slistptr traversal_list;

static int intcmp(const void *l, const void *r)
{
    return ((long)l - (long)r);
}

void list_action(const treenode *node)
{
    if (node) {
        traversal_list->push_back(traversal_list, node->data);
    }
}

void print_action(const treenode *node)
{
    if (node) {
        printf("[%ld]@%p ", (long)(node->data), node);
    } else {
        printf("null ");
    }
}

static void populate_tree(bstreeptr tree, long values[], size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        tree->insert(tree, (void*)values[i]);
    }
}

static void test_insert()
{
    bstreeptr tree = make_bstree(intcmp);
    long values[] = {10, 5, 15, 2, 7, 12, 18};

    tree->insert(tree, (void*)10);
    IS_TRUE(tree->root);
    EQUALS(tree->root->data, (void*)10);

    populate_tree(tree, values, sizeof(values)/sizeof(values[0]));

    // printf("%ld\n", (long)(tree->root->children[0]));
    IS_TRUE(tree->root->children[0]);
    EQUALS(tree->root->children[0]->data, (void*)5);

    IS_TRUE(tree->root->children[1]);
    EQUALS(tree->root->children[1]->data, (void*)15);

    if (traversal_list) {
        traversal_list->_destructor(traversal_list);
        traversal_list = NULL;
    }

    traversal_list = make_slist();
    tree->traverse_inorder(tree, list_action);
    long min = LONG_MIN;

    for (node *n1 = traversal_list->front(traversal_list); n1; n1 = n1->next) {
        IS_TRUE(min < (long)n1->data);
        min = (long)n1->data;
    }

    traversal_list->_destructor(traversal_list);
    tree->_destructor(tree);
}

static void test_find()
{
    bstreeptr tree = make_bstree(intcmp);
    long values[] = {2, 5, 7, 10, 12, 15, 18};
    size_t size = sizeof(values)/sizeof(values[0]);

    populate_tree(tree, values, size);

    for (int i = 0; i < size; ++i) {
        treenode *ptr = tree->find(tree, (void*)values[i]);
        IS_TRUE(ptr);
        EQUALS(ptr->data, (void*)values[i]);
    }

    long novalues[] = {0, 1, 3, 4, 6, 8, 9, 11, 13, 14, 16, 20};
    size = sizeof(novalues)/sizeof(novalues[0]);

    for (int i = 0; i < size; ++i) {
        treenode *ptr = tree->find(tree, (void*)novalues[i]);
        IS_TRUE(!ptr);
    }
}

static void test_remove()
{
    bstreeptr tree = make_bstree(intcmp);
    long values[] = {2, 5, 7, 10, 12, 15, 18};
    size_t size = sizeof(values)/sizeof(values[0]);

    populate_tree(tree, values, size);

    treenodeptr found = tree->find(tree, (void*)values[0]);
    treenodeptr popped = tree->remove(tree, (void*)values[0]);
    treenodeptr found_again = tree->find(tree, (void*)values[0]);
    EQUALS(found, popped);
    IS_TRUE(!found_again);
    tree->traverse_inorder(tree, print_action);
    putchar('\n');

    found = tree->find(tree, (void*)15);
    popped = tree->remove(tree, (void*)15);
    found_again = tree->find(tree, (void*)15);
    EQUALS(found, popped);
    IS_TRUE(!found_again);
    IS_TRUE(!tree->is_empty(tree));
    tree->traverse_inorder(tree, print_action);
    putchar('\n');

    found = tree->find(tree, (void*)10);
    popped = tree->remove(tree, (void*)10);
    found_again = tree->find(tree, (void*)10);
    EQUALS(found, popped);
    IS_TRUE(!found_again);
    IS_TRUE(!tree->is_empty(tree));
    tree->traverse_inorder(tree, print_action);
    putchar('\n');

    found = tree->find(tree, (void*)12);
    popped = tree->remove(tree, (void*)12);
    found_again = tree->find(tree, (void*)12);
    EQUALS(found, popped);
    IS_TRUE(!found_again);
    IS_TRUE(!tree->is_empty(tree));
    tree->traverse_inorder(tree, print_action);
    putchar('\n');

    found = tree->find(tree, (void*)15);
    popped = tree->remove(tree, (void*)15);
    found_again = tree->find(tree, (void*)15);
    IS_TRUE(!found);
    IS_TRUE(!popped);
    IS_TRUE(!found_again);
    IS_TRUE(!tree->is_empty(tree));

    found = tree->find(tree, (void*)18);
    popped = tree->remove(tree, (void*)18);
    found_again = tree->find(tree, (void*)18);
    EQUALS(found, popped);
    IS_TRUE(!found_again);
    IS_TRUE(!tree->is_empty(tree));
    tree->traverse_inorder(tree, print_action);
    putchar('\n');

    found = tree->find(tree, (void*)7);
    popped = tree->remove(tree, (void*)7);
    found_again = tree->find(tree, (void*)7);
    EQUALS(found, popped);
    IS_TRUE(!found_again);
    IS_TRUE(!tree->is_empty(tree));
    tree->traverse_inorder(tree, print_action);
    putchar('\n');

    found = tree->find(tree, (void*)5);
    popped = tree->remove(tree, (void*)5);
    found_again = tree->find(tree, (void*)5);
    EQUALS(found, popped);
    IS_TRUE(!found_again);
    IS_TRUE(tree->is_empty(tree));
}

int main()
{
    test_insert();
    test_find();
    test_remove();

    return 0;
}
