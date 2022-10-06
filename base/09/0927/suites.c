/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/6 下午3:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0927.c"

START_TEST(test_official_1) {
    int arr[]    = { 1, 0, 1, 0, 1 };
    int target[] = { 0, 3 };
    int len, *ans = threeEqualParts(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int arr[]    = { 1, 1, 0, 1, 1 };
    int target[] = { -1, -1 };
    int len, *ans = threeEqualParts(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int arr[]    = { 1, 1, 0, 0, 1 };
    int target[] = { 0, 2 };
    int len, *ans = threeEqualParts(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed_01) {
    int arr[]    = { 1, 0, 1, 1, 0 };
    int target[] = { -1, -1 };
    int len, *ans = threeEqualParts(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed_02) {
#include "failed_02.c"
    int target[] = { -1, -1 };
    int len, *ans = threeEqualParts(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_02);
    tcase_add_test(t, test_failed_01);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}