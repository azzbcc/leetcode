/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/1 19:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "lcp_24.c"

START_TEST(test_official_1) {
    int nums[] = { 3, 4, 5, 1, 6, 7 };
    int len, target[] = { 0, 0, 0, 5, 6, 7 };
    int *ans = numsGame(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 2, 3, 4, 5 };
    int len, target[] = { 0, 0, 0, 0, 0 };
    int *ans = numsGame(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int nums[] = { 1, 1, 1, 2, 3, 4 };
    int len, target[] = { 0, 1, 2, 3, 3, 3 };
    int *ans = numsGame(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_limit) {
    int len, nums[100000] = { 0 };
    int *ans = numsGame(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(nums));
    for (int i = 0, sum = 0; i < LEN(nums); ++i) {
        sum += (i + 1) / 2, sum %= MOD;
        ck_assert_int_eq(ans[i], sum);
    }
    free(ans);
}

START_TEST(test_failed) {
    int len;
#include "failed.c"
    int *ans = numsGame(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}