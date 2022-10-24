/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/24 上午11:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0915.c"

START_TEST(test_official_1) {
    int nums[] = { 5, 0, 3, 8, 6 };
    int target = 3, ans = partitionDisjoint(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 1, 1, 0, 6, 12 };
    int target = 4, ans = partitionDisjoint(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int nums[] = { 32, 57, 24, 19, 0, 24, 49, 67, 87, 87 };
    int target = 7, ans = partitionDisjoint(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}