/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/8 上午11:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0689.c"

START_TEST(test_official_1) {
    int nums[] = { 1, 2, 1, 2, 6, 7, 5, 1 }, k = 2;
    int target[] = { 0, 3, 5 };
    int len, *ans = maxSumOfThreeSubarrays(nums, LEN(nums), k, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 2, 1, 2, 1, 2, 1, 2, 1 }, k = 2;
    int target[] = { 0, 2, 4 };
    int len, *ans = maxSumOfThreeSubarrays(nums, LEN(nums), k, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_tle) {
#include "tle.c"
    int len, k = 4537, target[] = { 1333, 7427, 14873 };
    int *ans = maxSumOfThreeSubarrays(nums, LEN(nums), k, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}