/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/19 上午1:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1792.c"

START_TEST(test_official_1) {
    int extraStudents = 2, *classes[] = { (int[]) { 1, 2 }, (int[]) { 3, 5 }, (int[]) { 2, 2 } };
    double target = 0.78333, ans = maxAverageRatio(classes, LEN(classes), NULL, extraStudents);
    ck_assert_double_eq_tol(ans, target, 0.00001);
}

START_TEST(test_official_2) {
    int extraStudents = 4, *classes[] = { (int[]) { 2, 4 }, (int[]) { 3, 9 }, (int[]) { 4, 5 }, (int[]) { 2, 10 } };
    double target = 0.53485, ans = maxAverageRatio(classes, LEN(classes), NULL, extraStudents);
    ck_assert_double_eq_tol(ans, target, 0.00001);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}