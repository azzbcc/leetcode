/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/28 下午4:04
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0198.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 2, 3, 1 };
    int target = 4, ans = rob(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 2, 7, 9, 3, 1 };
    int target = 12, ans = rob(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int arr[]  = { 0 };
    int target = 0, ans = rob(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int arr[]  = { 2, 1 };
    int target = 2, ans = rob(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}
