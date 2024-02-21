/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/21 15:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "1372.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, null, 1, 1, 1, null, null, 1, 1, null, 1, null, null, null, 1, null, 1 };
    tree_t t   = tree_create(arr);
    int target = 3, ans = longestZigZag(t);
    ck_assert_int_eq(ans, target);
    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, 1, 1, null, 1, null, null, 1, 1, null, 1 };
    tree_t t   = tree_create(arr);
    int target = 4, ans = longestZigZag(t);
    ck_assert_int_eq(ans, target);
    tree_free(t);
}

START_TEST(test_official_3) {
    int arr[]  = { 1 };
    tree_t t   = tree_create(arr);
    int target = 0, ans = longestZigZag(t);
    ck_assert_int_eq(ans, target);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}