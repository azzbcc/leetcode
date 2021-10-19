/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/19 上午11:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0857.c"

START_TEST(test_official_1) {
    int quality[] = { 10, 20, 5 }, wage[] = { 70, 50, 30 }, K = 2;
    double target = 105, ans = mincostToHireWorkers(quality, LEN(quality), wage, LEN(wage), K);
    ck_assert_double_eq_tol(ans, target, 0.00001);
}

START_TEST(test_official_2) {
    int quality[] = { 3, 1, 10, 10, 1 }, wage[] = { 4, 8, 2, 2, 7 }, K = 3;
    double target = 30.66667, ans = mincostToHireWorkers(quality, LEN(quality), wage, LEN(wage), K);
    ck_assert_double_eq_tol(ans, target, 0.00001);
}

START_TEST(test_failed) {
    int quality[] = { 4, 4, 4, 5 }, wage[] = { 13, 12, 13, 12 }, K = 2;
    double target = 26, ans = mincostToHireWorkers(quality, LEN(quality), wage, LEN(wage), K);
    ck_assert_double_eq_tol(ans, target, 0.00001);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}