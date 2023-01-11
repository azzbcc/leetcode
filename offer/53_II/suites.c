/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/1/11 下午1:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "offer_53_II.c"

START_TEST(test_official_1) {
    int nums[] = { 0, 1, 3 };
    int target = 2, ans = missingNumber(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 0, 1, 2, 3, 4, 5, 6, 7, 9 };
    int target = 8, ans = missingNumber(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int nums[] = { 0, 1, 2 };
    int target = 3, ans = missingNumber(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}