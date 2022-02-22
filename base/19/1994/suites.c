/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/2/22 下午3:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1994.c"

START_TEST(test_official_1) {
    int nums[] = { 1, 2, 3, 4 };
    int target = 6, ans = numberOfGoodSubsets(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 4, 2, 3, 15 };
    int target = 5, ans = numberOfGoodSubsets(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int nums[] = { 1, 2, 2, 3, 4 };
    int target = 10, ans = numberOfGoodSubsets(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}