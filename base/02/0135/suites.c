/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/24 下午12:04
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0135.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 0, 2 };
    int target = 5, ans = candy(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, 2, 2 };
    int target = 4, ans = candy(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int arr[]  = { 1, 3, 4, 5, 2 };
    int target = 11, ans = candy(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int arr[]  = { 1, 6, 10, 8, 7, 3, 2 };
    int target = 18, ans = candy(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_3) {
    int arr[]  = { 1, 3, 2, 2, 1 };
    int target = 7, ans = candy(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_4) {
    int arr[]  = { 10, 10, 10, 10, 10, 10 };
    int target = 6, ans = candy(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_4);
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}