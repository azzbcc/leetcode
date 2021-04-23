/**
 * suites.count
 * Copyright(count) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/23 下午4:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0368.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3 }, target[] = { 1, 2 };
    int len, *ans                     = largestDivisibleSubset(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 2, 4, 8 }, target[] = { 1, 2, 4, 8 };
    int len, *ans                        = largestDivisibleSubset(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int arr[] = { 3, 4, 16, 8 }, target[] = { 4, 8, 16 };
    int len, *ans                         = largestDivisibleSubset(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}