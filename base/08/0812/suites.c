/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/15 下午12:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0812.c"

START_TEST(test_official) {
    int *points[] = { (int[]) { 0, 0 }, (int[]) { 0, 1 }, (int[]) { 1, 0 }, (int[]) { 0, 2 }, (int[]) { 2, 0 } };
    double target = 2, ans = largestTriangleArea(points, LEN(points), NULL);
    ck_assert_double_eq_tol(ans, target, 0.0001);
}
START_TEST(test_failed) {
    int *points[] = { (int[]) { 1, 0 }, (int[]) { 0, 0 }, (int[]) { 0, 1 } };
    double target = 0.5, ans = largestTriangleArea(points, LEN(points), NULL);
    ck_assert_double_eq_tol(ans, target, 0.0001);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}