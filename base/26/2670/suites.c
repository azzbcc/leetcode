/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/31 11:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2670.c"

START_TEST(test_official_1) {
    int len, nums[] = { 1, 2, 3, 4, 5 };
    int target[] = { -3, -1, 1, 3, 5 }, *ans = distinctDifferenceArray(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int len, nums[] = { 3, 2, 3, 4, 2 };
    int target[] = { -2, -1, 0, 2, 3 }, *ans = distinctDifferenceArray(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}