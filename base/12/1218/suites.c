/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/5 上午11:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1218.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 2, 3, 4 };
    int diff   = 1;
    int target = 4, ans = longestSubsequence(arr, LEN(arr), diff);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, 2, 3, 4 };
    int diff   = 1;
    int target = 4, ans = longestSubsequence(arr, LEN(arr), diff);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 1, 2, 3, 4 };
    int diff   = 1;
    int target = 4, ans = longestSubsequence(arr, LEN(arr), diff);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}