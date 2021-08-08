/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/24 上午11:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0674.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 3, 5, 4, 7, 9, 10, 11, 0 };
    int target = 5, ans = findLengthOfLCIS(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 2, 2, 2, 2, 2 };
    int target = 1, ans = findLengthOfLCIS(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_0) {
    int arr[]  = {};
    int target = 0, ans = findLengthOfLCIS(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int arr[]  = { 1 };
    int target = 1, ans = findLengthOfLCIS(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_0);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}