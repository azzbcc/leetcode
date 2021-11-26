/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/26 上午11:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0700.c"

START_TEST(test_official) {
    int arr[] = { 4, 2, 7, 1, 3 };
    tree_t t  = tree_create(arr);
    {
        int val       = 2;
        tree_t target = tree_find(t, val);
        tree_t ans    = searchBST(t, val);
        ck_assert_ptr_eq(ans, target);
    }
    {
        int val       = 5;
        tree_t target = tree_find(t, val);
        tree_t ans    = searchBST(t, val);
        ck_assert_ptr_eq(ans, target);
    }

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}