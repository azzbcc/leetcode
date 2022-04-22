/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/22 上午11:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0396.c"

START_TEST(test_official_1) {
    int nums[] = { 4, 3, 2, 6 };
    int target = 26, ans = maxRotateFunction(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int nums[] = { 100 };
    int target = 0, ans = maxRotateFunction(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
#include "failed.c"
    int target = -26472033, ans = maxRotateFunction(nums, LEN(nums));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}