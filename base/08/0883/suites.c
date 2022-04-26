/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/26 上午11:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0883.c"

START_TEST(test_official_1) {
    int *grid[] = { (int[]) { 1, 2 }, (int[]) { 3, 4 } };
    int target = 17, ans = projectionArea(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *grid[] = { (int[]) { 2 } };
    int target = 5, ans = projectionArea(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *grid[] = { (int[]) { 1, 0 }, (int[]) { 0, 2 } };
    int target = 8, ans = projectionArea(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}