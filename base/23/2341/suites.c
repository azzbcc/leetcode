/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/16 下午2:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2341.c"

START_TEST(test_official_1) {
    int nums[]   = { 1, 3, 2, 1, 3, 2, 2 };
    int target[] = { 3, 1 };
    int len, *ans = numberOfPairs(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int nums[]   = { 1, 1 };
    int target[] = { 1, 0 };
    int len, *ans = numberOfPairs(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int nums[]   = { 0 };
    int target[] = { 0, 1 };
    int len, *ans = numberOfPairs(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}