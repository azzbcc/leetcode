/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/28 下午12:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0905.c"

START_TEST(test_official_1) {
    int len, pos = 0;
    int nums[] = { 3, 1, 2, 4 };
    int *ans   = sortArrayByParity(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(nums));

    for (; pos < len && ans[pos] % 2 == 0; ++pos) {}
    for (; pos < len && ans[pos] % 2 == 1; ++pos) {}
    ck_assert_int_eq(pos, len);
    free(ans);
}

START_TEST(test_official_2) {
    int len, pos = 0;
    int nums[] = { 0 };
    int *ans   = sortArrayByParity(nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(nums));

    for (; pos < len && ans[pos] % 2 == 0; ++pos) {}
    for (; pos < len && ans[pos] % 2 == 1; ++pos) {}
    ck_assert_int_eq(pos, len);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}