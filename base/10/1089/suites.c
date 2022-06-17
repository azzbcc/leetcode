/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/6/17 上午11:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1089.c"

START_TEST(test_official_1) {
    int nums[]   = { 1, 0, 2, 3, 0, 4, 5, 0 };
    int target[] = { 1, 0, 0, 2, 3, 0, 0, 4 };

    duplicateZeros(nums, LEN(nums));
    ck_assert_mem_eq(nums, target, sizeof(target));
}

START_TEST(test_official_2) {
    int nums[]   = { 1, 2, 3 };
    int target[] = { 1, 2, 3 };

    duplicateZeros(nums, LEN(nums));
    ck_assert_mem_eq(nums, target, sizeof(target));
}

START_TEST(test_own) {
    int nums[]   = { 1, 2, 3, 0 };
    int target[] = { 1, 2, 3, 0 };

    duplicateZeros(nums, LEN(nums));
    ck_assert_mem_eq(nums, target, sizeof(target));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}