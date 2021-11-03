/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/3 下午8:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1331.c"

START_TEST(test_official_1) {
    int arr[]    = { 40, 10, 20, 30 };
    int target[] = { 4, 1, 2, 3 };
    int len, *ans = arrayRankTransform(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int arr[]    = { 100, 100, 100 };
    int target[] = { 1, 1, 1 };
    int len, *ans = arrayRankTransform(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int arr[]    = { 37, 12, 28, 9, 100, 56, 80, 5, 12 };
    int target[] = { 5, 3, 4, 2, 8, 6, 7, 1, 3 };
    int len, *ans = arrayRankTransform(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}