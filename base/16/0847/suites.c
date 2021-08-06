/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/6 上午10:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0847.c"

START_TEST(test_official_1) {
    int col[]   = { 3, 1, 1, 1 };
    int *grid[] = { (int[]) { 1, 2, 3 }, (int[]) { 0 }, (int[]) { 0 }, (int[]) { 0 } };
    int target = 4, ans = shortestPathLength(grid, LEN(grid), col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int col[]   = { 1, 3, 3, 1, 2 };
    int *grid[] = { (int[]) { 1 }, (int[]) { 0, 2, 4 }, (int[]) { 1, 3, 4 }, (int[]) { 2 }, (int[]) { 1, 2 } };
    int target = 4, ans = shortestPathLength(grid, LEN(grid), col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}