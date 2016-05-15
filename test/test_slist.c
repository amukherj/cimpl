#include "slist.h"
#include "test.h"

static void test_make_slist()
{
    slistptr lst = make_slist();

    IS_TRUE(lst->is_empty(lst));
}

static void test_push_pop()
{
    slistptr lst = make_slist();

    void *data1 = (void*)10;
    lst->push_back(lst, data1);
    void *data2 = (void*)20;
    lst->push_back(lst, data2);
    void *data3 = (void*)30;
    lst->push_back(lst, data3);

    nodeptr popped = lst->pop_back(lst);
    EQUALS(popped->data, (void*)30);
    popped->_destructor(popped);

    popped = lst->pop_back(lst);
    EQUALS(popped->data, (void*)20);
    popped->_destructor(popped);

    popped = lst->pop_back(lst);
    EQUALS(popped->data, (void*)10);
    popped->_destructor(popped);

    popped = lst->pop_back(lst);
    EQUALS(popped, NULL);

    IS_TRUE(lst->is_empty(lst));
}

static void test_pop_front()
{
    slistptr lst = make_slist();

    void *data1 = (void*)10;
    lst->push_back(lst, data1);
    void *data2 = (void*)20;
    lst->push_back(lst, data2);
    void *data3 = (void*)30;
    lst->push_back(lst, data3);

    nodeptr popped = lst->pop_front(lst);
    EQUALS(popped->data, (void*)10);
    popped->_destructor(popped);

    popped = lst->pop_front(lst);
    EQUALS(popped->data, (void*)20);
    popped->_destructor(popped);

    popped = lst->pop_front(lst);
    EQUALS(popped->data, (void*)30);
    popped->_destructor(popped);

    popped = lst->pop_front(lst);
    EQUALS(popped, NULL);

    IS_TRUE(lst->is_empty(lst));
}

int main()
{
    test_make_slist();
    test_push_pop();
    test_pop_front();

    return 0;
}
