/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/5/18 17:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1073.c"

START_TEST(test_official_1) {
    int arr1[] = { 1, 1, 1, 1, 1 }, arr2[] = { 1, 0, 1 };
    int target[] = { 1, 0, 0, 0, 0 };
    int len, *ans = addNegabinary(arr1, LEN(arr1), arr2, LEN(arr2), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int arr1[] = { 0 }, arr2[] = { 0 };
    int target[] = { 0 };
    int len, *ans = addNegabinary(arr1, LEN(arr1), arr2, LEN(arr2), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int arr1[] = { 0 }, arr2[] = { 1 };
    int target[] = { 1 };
    int len, *ans = addNegabinary(arr1, LEN(arr1), arr2, LEN(arr2), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_own) {
    int arr1[] = { 1 }, arr2[] = { 1 };
    int target[] = { 1, 1, 0 };
    int len, *ans = addNegabinary(arr1, LEN(arr1), arr2, LEN(arr2), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed_01) {
    int arr1[] = { 1 }, arr2[] = { 1, 1 };
    int target[] = { 0 };
    int len, *ans = addNegabinary(arr1, LEN(arr1), arr2, LEN(arr2), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed_02) {
#include "failed_02.c"
    int len, *ans = addNegabinary(arr1, LEN(arr1), arr2, LEN(arr2), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_02);
    tcase_add_test(t, test_failed_01);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}