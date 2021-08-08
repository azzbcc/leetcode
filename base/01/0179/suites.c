/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/12 下午12:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0179.c"

START_TEST(test_official_1) {
    int arr[]    = { 10, 2 };
    char *target = "210", *ans = largestNumber(arr, LEN(arr));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]    = { 3, 30, 34, 5, 9 };
    char *target = "9534330", *ans = largestNumber(arr, LEN(arr));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]    = { 1 };
    char *target = "1", *ans = largestNumber(arr, LEN(arr));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_4) {
    int arr[]    = { 10 };
    char *target = "10", *ans = largestNumber(arr, LEN(arr));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed) {
    int arr[]    = { 0, 0 };
    char *target = "0", *ans = largestNumber(arr, LEN(arr));
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}