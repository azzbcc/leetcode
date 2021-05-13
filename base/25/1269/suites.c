/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/5/13 下午5:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1269.c"

START_TEST(test_official_1) {
    int steps = 3, arrLen = 2;
    int target = 4, ans = numWays(steps, arrLen);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int steps = 2, arrLen = 4;
    int target = 2, ans = numWays(steps, arrLen);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int steps = 4, arrLen = 2;
    int target = 8, ans = numWays(steps, arrLen);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int steps = 27, arrLen = 7;
    int target = 127784505, ans = numWays(steps, arrLen);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}