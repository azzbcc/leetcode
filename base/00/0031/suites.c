/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/10 下午8:01
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdlib.h>
#include <stdbool.h>

#include "0031.c"

START_TEST(test_official_1) {
    int arr[]    = { 1, 2, 3 };
    int target[] = { 1, 3, 2 };

    nextPermutation(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_mem_eq(arr, target, sizeof(target));
}

START_TEST(test_official_2) {
    int arr[]    = { 3, 2, 1 };
    int target[] = { 1, 2, 3 };

    nextPermutation(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_mem_eq(arr, target, sizeof(target));
}

START_TEST(test_official_3) {
    int arr[]    = { 1, 1, 5 };
    int target[] = { 1, 5, 1 };

    nextPermutation(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_mem_eq(arr, target, sizeof(target));
}

START_TEST(test_own) {
    int arr[]    = { 2, 4, 3, 2 };
    int target[] = { 3, 2, 2, 4 };

    nextPermutation(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_mem_eq(arr, target, sizeof(target));
}

START_TEST(test_failed) {
    int arr[]    = { 2, 3, 1 };
    int target[] = { 3, 1, 2 };

    nextPermutation(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_mem_eq(arr, target, sizeof(target));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}