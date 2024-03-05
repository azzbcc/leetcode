/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/5 14:00
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1976.c"

START_TEST(test_official_1) {
    int n        = 7;
    int *roads[] = { (int[]) { 0, 6, 7 }, (int[]) { 0, 1, 2 }, (int[]) { 1, 2, 3 }, (int[]) { 1, 3, 3 },
                     (int[]) { 6, 3, 3 }, (int[]) { 3, 5, 1 }, (int[]) { 6, 5, 1 }, (int[]) { 2, 5, 1 },
                     (int[]) { 0, 4, 5 }, (int[]) { 4, 6, 2 } };
    int target = 4, ans = countPaths(n, roads, LEN(roads), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 2, *roads[] = { (int[]) { 1, 0, 10 } };
    int target = 1, ans = countPaths(n, roads, LEN(roads), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_01) {
    int n = 47;
#include "failed_01.c"
    int target = 936494446, ans = countPaths(n, roads, LEN(roads), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_02) {
    int n = 200;
#include "failed_02.c"
    int target = 1, ans = countPaths(n, roads, LEN(roads), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_02);
    tcase_add_test(t, test_failed_01);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}