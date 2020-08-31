/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/26 上午11:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0581.c"

START_TEST(test_official) {
    int arr[]  = { 2, 6, 4, 8, 10, 9, 15 };
    int target = 5, ans = findUnsortedSubarray(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_own) {
    int arr[]  = { 1, 2, 4, 6, 5, 3, 9, 7, 8 };
    int target = 7, ans = findUnsortedSubarray(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_zero) {
    int arr[]  = { 1, 2, 4 };
    int target = 0, ans = findUnsortedSubarray(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_limit) {
    int arr[]  = { 1, 3, 2, 4 };
    int target = 2, ans = findUnsortedSubarray(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_zero);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official);
}