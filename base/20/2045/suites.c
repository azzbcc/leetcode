/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/24 下午4:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2045.c"

START_TEST(test_official_1) {
    int *edges[] = { (int[]) { 1, 2 }, (int[]) { 1, 3 }, (int[]) { 1, 4 }, (int[]) { 3, 4 }, (int[]) { 4, 5 } };
    int n = 5, time = 3, change = 5;
    int target = 13, ans = secondMinimum(n, edges, LEN(edges), NULL, time, change);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *edges[] = { (int[]) { 1, 2 } };
    int n = 2, time = 3, change = 2;
    int target = 11, ans = secondMinimum(n, edges, LEN(edges), NULL, time, change);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int *edges[] = { (int[]) { 1, 2 },  (int[]) { 1, 3 },  (int[]) { 3, 4 }, (int[]) { 2, 5 },
                     (int[]) { 4, 6 },  (int[]) { 2, 7 },  (int[]) { 1, 8 }, (int[]) { 5, 9 },
                     (int[]) { 3, 10 }, (int[]) { 8, 11 }, (int[]) { 6, 12 } };
    int n = 12, time = 60, change = 600;
    int target = 360, ans = secondMinimum(n, edges, LEN(edges), NULL, time, change);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
#include "failed_02.c"
    int n = 520, time = 946, change = 183;
    int target = 3142, ans = secondMinimum(n, edges, LEN(edges), NULL, time, change);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle) {
#include "tle.c"
    int n = 10000, time = 1000, change = 1000;
    int target = 19983000, ans = secondMinimum(n, edges, LEN(edges), NULL, time, change);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}