/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/12 11:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1483.c"

START_TEST(test_official) {
    int n = 7, parent[] = { -1, 0, 0, 1, 1, 2, 2 };
    TreeAncestor *ancestor = treeAncestorCreate(n, parent, LEN(parent));
    ck_assert_ptr_nonnull(ancestor);

    int target[] = { 1, 0, -1 };
    int *args[]  = { (int[]) { 3, 1 }, (int[]) { 5, 2 }, (int[]) { 6, 3 } };
    for (int i = 0; i < LEN(args); ++i) {
        ck_assert_int_eq(treeAncestorGetKthAncestor(ancestor, args[i][0], args[i][1]), target[i]);
    }

    treeAncestorFree(ancestor);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}