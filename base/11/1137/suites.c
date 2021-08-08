/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/8 上午11:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1137.c"

START_TEST(test_official_1) {
    int n = 4;
    int target = 4, ans = tribonacci(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 25;
    int target = 1389537, ans = tribonacci(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}