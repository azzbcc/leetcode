/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/22 下午12:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0229.c"

START_TEST(test_official_1) {
    int arr[]    = { 3, 2, 3 };
    int target[] = { 3 };
    int len, *ans = majorityElement(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int arr[]    = { 1 };
    int target[] = { 1 };
    int len, *ans = majorityElement(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int arr[]    = { 1, 1, 1, 3, 3, 2, 2, 2 };
    int target[] = { 1, 2 };
    int len, *ans = majorityElement(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_own) {
    int arr[]    = { 1, 2, 2, 2, 3, 4 };
    int target[] = { 2 };
    int len, *ans = majorityElement(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int arr[]    = { 2, 1, 1, 3, 1, 4, 5, 6 };
    int target[] = { 1 };
    int len, *ans = majorityElement(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}