/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/8/4 14:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0980.c"

START_TEST(test_official_1) {
    int col     = 4;
    int *grid[] = { (int[]) { 1, 0, 0, 0 }, (int[]) { 0, 0, 0, 0 }, (int[]) { 0, 0, 2, -1 } };
    int target = 2, ans = uniquePathsIII(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int col     = 4;
    int *grid[] = { (int[]) { 1, 0, 0, 0 }, (int[]) { 0, 0, 0, 0 }, (int[]) { 0, 0, 0, 2 } };
    int target = 4, ans = uniquePathsIII(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int col     = 2;
    int *grid[] = { (int[]) { 0, 1 }, (int[]) { 2, 0 } };
    int target = 0, ans = uniquePathsIII(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}