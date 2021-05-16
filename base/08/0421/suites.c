/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/5/16 下午8:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0421.c"

START_TEST(test_official_1) {
    int arr[]  = { 3, 10, 5, 25, 2, 8 };
    int target = 28, ans = findMaximumXOR(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 0 };
    int target = 0, ans = findMaximumXOR(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 2, 4 };
    int target = 6, ans = findMaximumXOR(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int arr[]  = { 8, 10, 2 };
    int target = 10, ans = findMaximumXOR(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int arr[]  = { 14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70 };
    int target = 127, ans = findMaximumXOR(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle) {
#include "tle.c"
    int target = 16777215, ans = findMaximumXOR(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}