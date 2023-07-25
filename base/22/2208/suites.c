/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/25 15:28
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2208.c"

START_TEST(test_official_1) {
    int nums[] = { 5, 19, 8, 1 };
    int target = 3, ans = halveArray(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 3, 8, 20 };
    int target = 3, ans = halveArray(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_overflow) {
#include "overflow.c"
    int target = 10020, ans = halveArray(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_overflow);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}