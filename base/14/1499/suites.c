/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/21 22:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1499.c"

START_TEST(test_official_1) {
    int *points[] = { (int[]) { 1, 3 }, (int[]) { 2, 0 }, (int[]) { 5, 10 }, (int[]) { 6, -10 } }, k = 1;
    int target = 4, ans = findMaxValueOfEquation(points, LEN(points), NULL, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *points[] = { (int[]) { 0, 0 }, (int[]) { 3, 0 }, (int[]) { 9, 2 } }, k = 3;
    int target = 3, ans = findMaxValueOfEquation(points, LEN(points), NULL, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}