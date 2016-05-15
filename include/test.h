#ifndef CIMPL_TEST_H
#define CIMPL_TEST_H

#include <stdio.h>

#define IS_TRUE_MSG(expr, msg) \
    do { \
        if (!(expr)) { \
            fprintf(stderr, "%s: [%s] is false: %s\n", __PRETTY_FUNCTION__, \
                #expr, msg); \
        } \
    } while (0)

#define IS_TRUE(expr) IS_TRUE_MSG((expr), "")

#define EQUALS_MSG(expr1, expr2, msg) \
    do { \
        if ((expr1) != (expr2)) { \
            fprintf(stderr, "%s: [%s] and [%s] are not equal: %s\n", \
                __PRETTY_FUNCTION__, #expr1, #expr2, msg); \
        } \
    } while (0)

#define EQUALS(expr1, expr2) EQUALS_MSG((expr1), (expr2), "")

#define NOT_EQUALS_MSG(expr1, expr2, msg) \
    do { \
        if ((expr1) == (expr2)) { \
            fprintf(stderr, "%s: [%s] and [%s] are not unequal: %s\n", \
                            __PRETTY_FUNCTION__, #expr1, #expr2, msg); \
        } \
    } while (0)

#define NOT_EQUALS(expr1, expr2) NOT_EQUALS_MSG((expr1), (expr2), "")

#endif /* CIMPL_TEST_H */
