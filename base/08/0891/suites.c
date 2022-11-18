/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/18 下午4:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0891.c"

START_TEST(test_official_1) {
    int nums[] = { 2, 1, 3 };
    int target = 6, ans = sumSubseqWidths(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 2 };
    int target = 0, ans = sumSubseqWidths(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int times = 100000, nums[times];
    for (int i = 0; i < times; ++i) {
        nums[i] = i + 1;
    }
    int target = 528504053, ans = sumSubseqWidths(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}