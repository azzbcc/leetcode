/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/6 15:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "lcp_30.c"

START_TEST(test_official_1) {
    int nums[] = { 100, 100, 100, -250, -60, -140, -50, -50, 100, 150 };
    int target = 1, ans = magicTower(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { -200, -300, 400, 0 };
    int target = -1, ans = magicTower(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_01) {
#include "failed_01.c"
    int target = 8, ans = magicTower(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_02) {
#include "failed_02.c"
    int target = 12, ans = magicTower(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_overflow) {
    int len = 100000, nums[len];
    for (int i = 0; i < len; ++i) {
        nums[i] = len * (len / 2 > i ? 1 : -1);
    }
    int target = 0, ans = magicTower(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_overflow);
    tcase_add_test(t, test_failed_02);
    tcase_add_test(t, test_failed_01);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}