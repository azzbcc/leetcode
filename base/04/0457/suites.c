/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/7 下午10:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0457.c"

START_TEST(test_official_1) {
    int nums[]  = { 2, -1, 1, 2, 2 };
    bool target = true, ans = circularArrayLoop(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[]  = { -1, 2 };
    bool target = false, ans = circularArrayLoop(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[]  = { -2, 1, -1, -2, -2 };
    bool target = false, ans = circularArrayLoop(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int nums[]  = { -1, -1, -1 };
    bool target = true, ans = circularArrayLoop(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}