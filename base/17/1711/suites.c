/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/7 上午11:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1711.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 3, 5, 7, 9 };
    int target = 4, ans = countPairs(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, 1, 1, 3, 3, 3, 7 };
    int target = 15, ans = countPairs(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int arr[]  = { 1, 1, 1, 3, 3, 3, 7, 0, 0, 0 };
    int target = 24, ans = countPairs(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_01) {
    int arr[]  = { 2160, 1936, 3,    29,  27, 5, 2503, 1593, 2, 0, 16,  0,    3860, 28908, 6, 2, 15, 49,  6246, 1946,
                  23,   105,  7996, 196, 0,  2, 55,   457,  5, 3, 924, 7268, 16,   48,    4, 0, 12, 116, 2628, 1468 };
    int target = 53, ans = countPairs(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_02) {
    int arr[100000];
    for (int i = 0; i < LEN(arr); arr[i++] = 32) {}
    int target = 999949972, ans = countPairs(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_01);
    tcase_add_test(t, test_failed_02);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}