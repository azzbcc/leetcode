/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/23 上午11:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1630.c"

START_TEST(test_official_1) {
    int len, nums[] = { 4, 6, 5, 9, 3, 7 }, l[] = { 0, 0, 2 }, r[] = { 2, 3, 5 };
    bool target[] = { true, false, true }, *ans = checkArithmeticSubarrays(nums, LEN(nums), l, LEN(l), r, LEN(r), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int len, nums[] = { -12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10 };
    int l[] = { 0, 1, 6, 4, 8, 7 }, r[] = { 4, 4, 9, 7, 9, 10 };
    bool target[] = { false, true, false, false, true, true },
         *ans     = checkArithmeticSubarrays(nums, LEN(nums), l, LEN(l), r, LEN(r), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int len, nums[] = { -3, -6, -8, -4, -2, -8, -6, 0, 0, 0, 0 };
    int l[] = { 5, 4, 3, 2, 4, 7, 6, 1, 7 }, r[] = { 6, 5, 6, 3, 7, 10, 7, 4, 10 };
    bool target[] = { true, true, true, true, false, true, true, true, true },
         *ans     = checkArithmeticSubarrays(nums, LEN(nums), l, LEN(l), r, LEN(r), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}
