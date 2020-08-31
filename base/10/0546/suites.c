/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/17 下午12:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdio.h>
#include <stdbool.h>

#include "0546.c"

START_TEST(test_official) {
    int arr[]  = { 1, 3, 2, 2, 2, 3, 4, 3, 1 };
    int target = 23, ans = removeBoxes(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_own) {
    int arr[]  = { 1, 2, 1, 2, 1, 2 };
    int target = 12, ans = removeBoxes(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_tle) {
    int arr[]  = { 3, 8,  8, 5, 5, 3, 9, 2, 4, 4, 6, 5, 8, 4, 8, 6, 9, 6, 2, 8, 6,  4, 1, 9,  5,
                  3, 10, 5, 3, 3, 9, 8, 8, 6, 5, 3, 7, 4, 9, 6, 3, 9, 4, 3, 5, 10, 7, 6, 10, 7 };
    int target = 136, ans = removeBoxes(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}
START_TEST(test_limit) {
    int arr[]  = { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2,
                  1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2,
                  1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2 };
    int target = 2550, ans = removeBoxes(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official);
}