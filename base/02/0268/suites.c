/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/14 下午1:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0268.c"

START_TEST(test_official_1) {
    int nums[] = { 3, 0, 1 };
    int target = 2, ans = missingNumber(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 0, 1 };
    int target = 2, ans = missingNumber(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int nums[] = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
    int target = 8, ans = missingNumber(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int nums[] = { 0 };
    int target = 1, ans = missingNumber(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}