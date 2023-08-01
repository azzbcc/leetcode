/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/8/1 14:39
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2681.c"

START_TEST(test_official_1) {
    int nums[] = { 2, 1, 4 };
    int target = 141, ans = sumOfPower(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 1, 1 };
    int target = 7, ans = sumOfPower(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int nums[100000];
    for (int i = 0; i < LEN(nums); nums[i++] = 999999999) {}
    int target = 845560456, ans = sumOfPower(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}