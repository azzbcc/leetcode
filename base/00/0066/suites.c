/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/16 下午3:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0066.c"

START_TEST(test_official_1) {
    int arr[]    = { 1, 2, 3 };
    int target[] = { 1, 2, 4 };
    int len, *ans = plusOne(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int arr[]    = { 4, 3, 2, 1 };
    int target[] = { 4, 3, 2, 2 };
    int len, *ans = plusOne(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int arr[]    = { 0 };
    int target[] = { 1 };
    int len, *ans = plusOne(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_own) {
    int arr[]    = { 9, 9, 9, 9, 9 };
    int target[] = { 1, 0, 0, 0, 0, 0 };
    int len, *ans = plusOne(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}