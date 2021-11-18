/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/18 上午11:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0563.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3 };
    tree_t t  = tree_create(arr);

    int target = 1, ans = findTilt(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[] = { 4, 2, 9, 3, 5, null, 7 };
    tree_t t  = tree_create(arr);

    int target = 15, ans = findTilt(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_official_3) {
    int arr[] = { 21, 7, 14, 1, 1, 2, 2, 3, 3 };
    tree_t t  = tree_create(arr);

    int target = 9, ans = findTilt(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}