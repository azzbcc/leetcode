/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/5/24 11:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1377.c"

START_TEST(test_official_1) {
    int n = 7, t = 2, target = 4;
    int *edges[] = { (int[]) { 1, 2 }, (int[]) { 1, 3 }, (int[]) { 1, 7 },
                     (int[]) { 2, 4 }, (int[]) { 2, 6 }, (int[]) { 3, 5 } };
    double tt = 0.16666666666666666, ans = frogPosition(n, edges, LEN(edges), NULL, t, target);
    ck_assert_double_eq_tol(ans, tt, 0.00001);
}

START_TEST(test_official_2) {
    int n = 7, t = 1, target = 7;
    int *edges[] = { (int[]) { 1, 2 }, (int[]) { 1, 3 }, (int[]) { 1, 7 },
                     (int[]) { 2, 4 }, (int[]) { 2, 6 }, (int[]) { 3, 5 } };
    double tt = 0.3333333333333333, ans = frogPosition(n, edges, LEN(edges), NULL, t, target);
    ck_assert_double_eq_tol(ans, tt, 0.00001);
}

START_TEST(test_failed_1) {
    int n = 7, t = 20, target = 6;
    int *edges[] = { (int[]) { 1, 2 }, (int[]) { 1, 3 }, (int[]) { 1, 7 },
                     (int[]) { 2, 4 }, (int[]) { 2, 6 }, (int[]) { 3, 5 } };
    double tt = 0.16666666666666666, ans = frogPosition(n, edges, LEN(edges), NULL, t, target);
    ck_assert_double_eq_tol(ans, tt, 0.00001);
}

START_TEST(test_failed_2) {
    int n = 1, t = 1, target = 1;
    int *edges[] = {};
    double tt = 1, ans = frogPosition(n, edges, LEN(edges), NULL, t, target);
    ck_assert_double_eq_tol(ans, tt, 0.00001);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}