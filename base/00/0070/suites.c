/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/28 下午3:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0070.c"

START_TEST(test_official_1) {
    int n      = 2;
    int target = 2, ans = climbStairs(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 3;
    int target = 3, ans = climbStairs(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}