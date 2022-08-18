/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/18 下午12:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1224.c"

START_TEST(test_official_1) {
    int nums[] = { 2, 2, 1, 1, 5, 3, 3, 5 };
    int target = 7, ans = maxEqualFreq(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5 };
    int target = 13, ans = maxEqualFreq(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int nums[] = { 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 5 };
    int target = 11, ans = maxEqualFreq(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}