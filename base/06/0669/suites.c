/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/9/29 下午8:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0669.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 0, 2 }, low = 1, high = 2;
    int t[] = { 1, null, 2 };

    tree_t root   = tree_create(arr);
    tree_t target = tree_create(t);
    tree_t ans    = trimBST(root, low, high);
    ck_assert(tree_equal(ans, target));

    tree_free(ans);
    tree_free(target);
}

START_TEST(test_official_2) {
    int arr[] = { 3, 0, 4, null, 2, null, null, 1 }, low = 1, high = 3;
    int t[] = { 3, 2, null, 1 };

    tree_t root   = tree_create(arr);
    tree_t target = tree_create(t);
    tree_t ans    = trimBST(root, low, high);
    ck_assert(tree_equal(ans, target));

    tree_free(ans);
    tree_free(target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}