/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/9 14:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0236.c"

START_TEST(test_official_1) {
    int p = 5, q = 1, target = 3;
    int arr[]  = { 3, 5, 1, 6, 2, 0, 8, null, null, 7, 4 };
    tree_t ta  = tree_create(arr);
    tree_t ans = lowestCommonAncestor(ta, tree_find(ta, p), tree_find(ta, q));
    ck_assert_ptr_eq(ans, tree_find(ta, target));
    tree_free(ta);
}

START_TEST(test_official_2) {
    int p = 5, q = 4, target = 5;
    int arr[]  = { 3, 5, 1, 6, 2, 0, 8, null, null, 7, 4 };
    tree_t ta  = tree_create(arr);
    tree_t ans = lowestCommonAncestor(ta, tree_find(ta, p), tree_find(ta, q));
    ck_assert_ptr_eq(ans, tree_find(ta, target));
    tree_free(ta);
}

START_TEST(test_official_3) {
    int p = 1, q = 2, target = 1;
    int arr[]  = { 1, 2 };
    tree_t ta  = tree_create(arr);
    tree_t ans = lowestCommonAncestor(ta, tree_find(ta, p), tree_find(ta, q));
    ck_assert_ptr_eq(ans, tree_find(ta, target));
    tree_free(ta);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}