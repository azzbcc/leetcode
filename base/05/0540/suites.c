/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/2/14 上午11:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0540.c"

START_TEST(test_official_1) {
    int nums[] = { 1, 1, 2, 3, 3, 4, 4, 8, 8 };
    int target = 2, ans = singleNonDuplicate(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 3, 3, 7, 7, 10, 11, 11 };
    int target = 10, ans = singleNonDuplicate(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}