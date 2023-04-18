/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/18 下午12:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "1026.c"

START_TEST(test_official_1) {
    int arr[]   = { 8, 3, 10, 1, 6, null, 14, null, null, 4, 7, 13 };
    tree_t root = tree_create(arr);
    int target = 7, ans = maxAncestorDiff(root);
    ck_assert_int_eq(ans, target);
    tree_free(root);
}

START_TEST(test_official_2) {
    int arr[]   = { 1, null, 2, null, 0, 3 };
    tree_t root = tree_create(arr);
    int target = 3, ans = maxAncestorDiff(root);
    ck_assert_int_eq(ans, target);
    tree_free(root);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}