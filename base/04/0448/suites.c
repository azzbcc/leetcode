/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/13 上午10:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0448.c"

START_TEST(test_official) {
    int arr[]    = { 4, 3, 2, 7, 8, 2, 3, 1 };
    int target[] = { 5, 6 };
    int len, *ans = findDisappearedNumbers(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed_1) {
    int arr[]    = { 1, 1 };
    int target[] = { 2 };
    int len, *ans = findDisappearedNumbers(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed_2) {
    int arr[]    = { 2, 2 };
    int target[] = { 1 };
    int len, *ans = findDisappearedNumbers(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed_3) {
    int arr[]    = { 2, 1 };
    int target[] = {};
    int len, *ans = findDisappearedNumbers(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official);
}