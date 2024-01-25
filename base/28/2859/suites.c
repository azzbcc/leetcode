/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/25 10:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2859.c"

START_TEST(test_official_1) {
    int nums[] = { 5, 10, 1, 5, 2 }, k = 1;
    int target = 13, ans = sumIndicesWithKSetBits(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 4, 3, 2, 1 }, k = 2;
    int target = 1, ans = sumIndicesWithKSetBits(nums, LEN(nums), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}