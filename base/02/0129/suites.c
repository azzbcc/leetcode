/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/29 上午11:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0129.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 2, 3 };
    tree_t t   = tree_create(arr);
    int target = 25, ans = sumNumbers(t);

    ck_assert_int_eq(target, ans);

    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[]  = { 4, 9, 0, 5, 1 };
    tree_t t   = tree_create(arr);
    int target = 1026, ans = sumNumbers(t);

    ck_assert_int_eq(target, ans);

    tree_free(t);
}

START_TEST(test_failed) {
    int arr[]  = { 0, 1 };
    tree_t t   = tree_create(arr);
    int target = 1, ans = sumNumbers(t);

    ck_assert_int_eq(target, ans);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}