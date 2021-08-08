/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/27 上午10:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0671.c"

START_TEST(test_official_1) {
    int arr[] = { 2, 2, 5, null, null, 5, 7 };
    tree_t t  = tree_create(arr);

    int target = 5, ans = findSecondMinimumValue(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[] = { 2, 2, 2 };
    tree_t t  = tree_create(arr);

    int target = -1, ans = findSecondMinimumValue(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_own_1) {
    int arr[] = { 2, 2, 2, 2, 4, 5, 2 };
    tree_t t  = tree_create(arr);

    int target = 4, ans = findSecondMinimumValue(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_own_2) {
    int arr[] = { 2, 2, 2, 2, 4, 2, 2 };
    tree_t t  = tree_create(arr);

    int target = 4, ans = findSecondMinimumValue(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_failed) {
    int arr[] = { 1, 1, 3, 1, 1, 3, 4, 3, 1, 1, 1, 3, 8, 4, 8, 3, 3, 1, 6, 2, 1 };
    tree_t t  = tree_create(arr);

    tree_print(t);

    int target = 2, ans = findSecondMinimumValue(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own_1);
    tcase_add_test(t, test_own_2);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}