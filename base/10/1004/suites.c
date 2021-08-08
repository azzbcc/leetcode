/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/19 上午12:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1004.c"

START_TEST(test_official_1) {
    int K = 2, arr[] = { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };
    int target = 6, ans = longestOnes(arr, LEN(arr), K);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int K = 3, arr[] = { 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 };
    int target = 10, ans = longestOnes(arr, LEN(arr), K);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}