/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/19 上午11:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0283.c"

START_TEST(test_official) {
    int arr[]    = { 0, 1, 0, 3, 12 };
    int target[] = { 1, 3, 12, 0, 0 };

    moveZeroes(arr, LEN(arr));

    ck_assert_mem_eq(arr, target, sizeof(target));
}

START_TEST(test_own_1) {
    int arr[]    = { 0, 0, 0, 0, 0, 0 };
    int target[] = { 0, 0, 0, 0, 0, 0 };

    moveZeroes(arr, LEN(arr));

    ck_assert_mem_eq(arr, target, sizeof(target));
}

START_TEST(test_own_2) {
    int arr[]    = { 1, 2, 3, 4, 5 };
    int target[] = { 1, 2, 3, 4, 5 };

    moveZeroes(arr, LEN(arr));

    ck_assert_mem_eq(arr, target, sizeof(target));
}

START_TEST(test_failed) {
    int arr[]    = { 1, 0 };
    int target[] = { 1, 0 };

    moveZeroes(arr, LEN(arr));

    ck_assert_mem_eq(arr, target, sizeof(target));
}

START_TEST(test_own_3) {
    int arr[]    = { 1, 0, 2 };
    int target[] = { 1, 2, 0 };

    moveZeroes(arr, LEN(arr));

    ck_assert_mem_eq(arr, target, sizeof(target));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own_3);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own_1);
    tcase_add_test(t, test_own_2);
    tcase_add_test(t, test_official);
}