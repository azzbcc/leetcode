/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/12 下午5:48
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0334.c"

START_TEST(test_official_1) {
    int nums[]  = { 1, 2, 3, 4, 5 };
    bool target = true, ans = increasingTriplet(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[]  = { 5, 4, 3, 2, 1 };
    bool target = false, ans = increasingTriplet(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[]  = { 2, 1, 5, 0, 4, 6 };
    bool target = true, ans = increasingTriplet(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int nums[]  = { 5, 4, 6, 5, 4, 5 };
    bool target = false, ans = increasingTriplet(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}