/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/7 下午1:11
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0081.c"

START_TEST(test_official_1) {
    int arr[] = { 2, 5, 6, 0, 0, 1, 2 }, key = 0;
    bool target = true, ans = search(arr, LEN(arr), key);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[] = { 2, 5, 6, 0, 0, 1, 2 }, key = 3;
    bool target = false, ans = search(arr, LEN(arr), key);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int arr[] = { 1, 2, 3, 1, 1, 1, 1 }, key = 3;
    bool target = true, ans = search(arr, LEN(arr), key);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int arr[] = { 1, 0, 1, 1, 1 }, key = 0;
    bool target = true, ans = search(arr, LEN(arr), key);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int arr[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1 }, key = 2;
    bool target = true, ans = search(arr, LEN(arr), key);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_3) {
    int arr[] = { 1, 3, 5 }, key = 1;
    bool target = true, ans = search(arr, LEN(arr), key);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}