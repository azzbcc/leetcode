/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/29 上午11:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0330.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 3 }, n = 6;
    int target = 1, ans = minPatches(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 5, 10 }, n = 20;
    int target = 2, ans = minPatches(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[] = { 1, 2, 2 }, n = 5;
    int target = 0, ans = minPatches(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle) {
    int arr[] = { 1, 2, 31, 33 }, n = 2147483647;
    int target = 28, ans = minPatches(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}