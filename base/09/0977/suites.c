/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/16 上午11:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0977.c"

START_TEST(test_official_1) {
    int arr[] = { -4, -1, 0, 3, 10 }, target[] = { 0, 1, 9, 16, 100 };

    int len, *ans = sortedSquares(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int arr[] = { -7, -3, 2, 3, 11 }, target[] = { 4, 9, 9, 49, 121 };

    int len, *ans = sortedSquares(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_failed) {
    int arr[] = { 1 }, target[] = { 1 };

    int len, *ans = sortedSquares(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}