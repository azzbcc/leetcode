/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/25 上午10:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0658.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3, 4, 5 }, k = 4, x = 3;
    int target[] = { 1, 2, 3, 4 };
    int len, *ans = findClosestElements(arr, LEN(arr), k, x, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 2, 3, 4, 5 }, k = 4, x = -1;
    int target[] = { 1, 2, 3, 4 };
    int len, *ans = findClosestElements(arr, LEN(arr), k, x, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed_1) {
    int arr[] = { 1, 1, 1, 10, 10, 10 }, k = 1, x = 9;
    int target[] = { 10 };
    int len, *ans = findClosestElements(arr, LEN(arr), k, x, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed_2) {
    int arr[] = { 0, 1, 1, 1, 2, 3, 6, 7, 8, 9 }, k = 9, x = 4;
    int target[] = { 0, 1, 1, 1, 2, 3, 6, 7, 8 };
    int len, *ans = findClosestElements(arr, LEN(arr), k, x, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed_3) {
    int arr[] = { 0, 0, 1, 2, 3, 3, 4, 7, 7, 8 }, k = 3, x = 5;
    int target[] = { 3, 3, 4 };
    int len, *ans = findClosestElements(arr, LEN(arr), k, x, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}