#include "stack.h"
#include "test.h"

static void test_make_stack()
{
    stackptr stk = make_stack();
    IS_TRUE(stk);
    IS_TRUE(stk->is_empty(stk));
}

static void test_push_pop()
{
    stackptr stk = make_stack();
    stk->push(stk, (void*)80);
    stk->push(stk, (void*)90);
    stk->push(stk, (void*)100);

    node *ptr = stk->pop(stk);
    IS_TRUE(ptr && ptr->data == (void*)100);
    ptr = stk->pop(stk);
    IS_TRUE(ptr && ptr->data == (void*)90);
    ptr = stk->pop(stk);
    IS_TRUE(ptr && ptr->data == (void*)80);

    ptr = stk->pop(stk);
    IS_TRUE(!ptr);
    IS_TRUE(stk->is_empty(stk));
}

int main()
{
    test_make_stack();
    test_push_pop();
    return 0;
}
