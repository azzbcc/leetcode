/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/2/17 下午5:11
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0688.c"

START_TEST(test_official_1) {
    int n = 3, k = 2, row = 0, column = 0;
    double target = 0.0625, ans = knightProbability(n, k, row, column);
    ck_assert_double_eq_tol(ans, target, .00001);
}

START_TEST(test_official_2) {
    int n = 1, k = 0, row = 0, column = 0;
    double target = 1, ans = knightProbability(n, k, row, column);
    ck_assert_double_eq_tol(ans, target, .00001);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
//    tcase_add_test(t, test_official_2);
}