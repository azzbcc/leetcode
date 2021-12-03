/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/3 下午1:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1005.c"

START_TEST(test_official_1) {
    int nums[] = { 4, 2, 3 }, k = 1;
    int target = 5, ans = largestSumAfterKNegations(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 3, -1, 0, 2 }, k = 3;
    int target = 6, ans = largestSumAfterKNegations(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 2, -3, -1, 5, -4 }, k = 2;
    int target = 13, ans = largestSumAfterKNegations(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int nums[] = { -2, -1, 2 }, k = 3;
    int target = 3, ans = largestSumAfterKNegations(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int nums[] = { -4, -2, -3 }, k = 4;
    int target = 5, ans = largestSumAfterKNegations(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}