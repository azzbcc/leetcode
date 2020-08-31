/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/5 上午11:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0337.c"

START_TEST(test_official_1) {
    int arr[] = { 3, 2, 3, null, 3, null, 1 };
    tree_t ta = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));

    int target = 7, ans = rob(ta);
    ck_assert_msg(target == ans, "error, except %d but got %d on rob().", target, ans);

    tree_free(ta);
}

START_TEST(test_official_2) {
    int arr[] = { 3, 4, 5, 1, 3, null, 1 };
    tree_t ta = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));

    int target = 9, ans = rob(ta);
    ck_assert_msg(target == ans, "error, except %d but got %d on rob().", target, ans);

    tree_free(ta);
}

START_TEST(test_own) {
    int arr[] = { 1, 1, 2, 3 };
    tree_t ta = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));

    int target = 5, ans = rob(ta);
    ck_assert_msg(target == ans, "error, except %d but got %d on rob().", target, ans);

    tree_free(ta);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}