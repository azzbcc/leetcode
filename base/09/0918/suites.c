/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/20 00:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0918.c"

START_TEST(test_official_1) {
    int nums[] = { 1, -2, 3, -2 };
    int target = 3, ans = maxSubarraySumCircular(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 5, -3, 5 };
    int target = 10, ans = maxSubarraySumCircular(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 3, -2, 2, -3 };
    int target = 3, ans = maxSubarraySumCircular(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int nums[] = { -3, -2, -2, -3 };
    int target = -2, ans = maxSubarraySumCircular(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}