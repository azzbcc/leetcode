/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/29 16:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "10_03.c"

START_TEST(test_official_1) {
    int arr[] = { 15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14 };
    int t = 5, target = 8, ans = search(arr, LEN(arr), t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[] = { 15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14 };
    int t = 11, target = -1, ans = search(arr, LEN(arr), t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own_1) {
    int arr[] = { 5, 5, 4, 5, 5, 5, 5, 5, 5 };
    ck_assert_int_eq(2, search(arr, LEN(arr), 4));
    ck_assert_int_eq(0, search(arr, LEN(arr), 5));
}

START_TEST(test_own_2) {
    int arr[] = { 5, 5, 5, 5, 5, 5, 4, 5, 5 };
    ck_assert_int_eq(6, search(arr, LEN(arr), 4));
    ck_assert_int_eq(0, search(arr, LEN(arr), 5));
}

START_TEST(test_own_3) {
    int arr[] = { 5, 5, 5, 5, 6, 4, 5, 5, 5 };
    ck_assert_int_eq(5, search(arr, LEN(arr), 4));
    ck_assert_int_eq(0, search(arr, LEN(arr), 5));
    ck_assert_int_eq(4, search(arr, LEN(arr), 6));
}

START_TEST(test_own_4) {
    int arr[] = { 5, 5, 5, 6, 4, 5, 5, 5, 5 };
    ck_assert_int_eq(4, search(arr, LEN(arr), 4));
    ck_assert_int_eq(0, search(arr, LEN(arr), 5));
    ck_assert_int_eq(3, search(arr, LEN(arr), 6));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_own_1);
    tcase_add_test(t, test_own_2);
    tcase_add_test(t, test_own_3);
    tcase_add_test(t, test_own_4);
}