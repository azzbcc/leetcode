/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/15 下午12:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0213.c"

START_TEST(test_official_1) {
    int arr[]  = { 2, 3, 2 };
    int target = 3, ans = rob(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, 2, 3, 1 };
    int target = 4, ans = rob(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 0 };
    int target = 0, ans = rob(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int arr[]  = { 1 };
    int target = 1, ans = rob(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}