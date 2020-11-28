/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/28 下午1:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0493.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 3, 2, 3, 1 };
    int target = 2, ans = reversePairs(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 2, 4, 3, 5, 1 };
    int target = 3, ans = reversePairs(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int arr[]  = {};
    int target = 0, ans = reversePairs(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int arr[]  = { 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647 };
    int target = 0, ans = reversePairs(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}