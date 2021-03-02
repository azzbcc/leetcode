/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/2 下午12:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1776.c"

START_TEST(test_official_1) {
    int len, *cars[] = { (int[]) { 1, 2 }, (int[]) { 2, 1 }, (int[]) { 4, 3 }, (int[]) { 7, 2 } };
    double target[] = { 1.00000, -1.00000, 3.00000, -1.00000 };
    double *ans     = getCollisionTimes(cars, LEN(cars), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(ans[i], target[i], 0.001);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len, *cars[] = { (int[]) { 3, 4 }, (int[]) { 5, 4 }, (int[]) { 6, 3 }, (int[]) { 9, 1 } };
    double target[] = { 2.00000, 1.00000, 1.50000, -1.00000 };
    double *ans     = getCollisionTimes(cars, LEN(cars), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(ans[i], target[i], 0.001);
    }
    free(ans);
}

START_TEST(test_tle) {
#include "tle.c"
    int len;
    double *ans = getCollisionTimes(cars, LEN(cars), NULL, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq_tol(ans[i], target[i], 0.001);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}