/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/6 上午11:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0414.c"

START_TEST(test_official_1) {
    int arr[]  = { 3, 2, 1 };
    int target = 1, ans = thirdMax(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, 2 };
    int target = 2, ans = thirdMax(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 2, 2, 3, 1 };
    int target = 1, ans = thirdMax(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int arr[]  = { 1, 2, 2, 5, 3, 5 };
    int target = 2, ans = thirdMax(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}