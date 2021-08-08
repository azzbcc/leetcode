/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/5 下午2:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0075.c"

START_TEST(test_official_1) {
    int nums[]   = { 2, 0, 2, 1, 1, 0 };
    int target[] = { 0, 0, 1, 1, 2, 2 };

    sortColors(nums, LEN(nums));
    ck_assert_mem_eq(nums, target, sizeof(target));
}

START_TEST(test_official_2) {
    int nums[]   = { 2, 0, 1 };
    int target[] = { 0, 1, 2 };

    sortColors(nums, LEN(nums));
    ck_assert_mem_eq(nums, target, sizeof(target));
}

START_TEST(test_official_3) {
    int nums[]   = { 0 };
    int target[] = { 0 };

    sortColors(nums, LEN(nums));
    ck_assert_mem_eq(nums, target, sizeof(target));
}

START_TEST(test_official_4) {
    int nums[]   = { 1 };
    int target[] = { 1 };

    sortColors(nums, LEN(nums));
    ck_assert_mem_eq(nums, target, sizeof(target));
}

START_TEST(test_failed) {
    int nums[]   = { 2 };
    int target[] = { 2 };

    sortColors(nums, LEN(nums));
    ck_assert_mem_eq(nums, target, sizeof(target));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}