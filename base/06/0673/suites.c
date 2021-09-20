/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/20 下午12:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0673.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 3, 5, 4, 7 };
    int target = 2, ans = findNumberOfLIS(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 2, 2, 2, 2, 2 };
    int target = 5, ans = findNumberOfLIS(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int arr[]  = { 1, 3, 2 };
    int target = 2, ans = findNumberOfLIS(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int arr[]  = { 1, 2, 3, 1, 2, 3, 1, 2, 3 };
    int target = 10, ans = findNumberOfLIS(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}