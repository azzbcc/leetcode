/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/8/26 20:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1289.c"

START_TEST(test_official_1) {
    int *grid[] = { (int[]) { 1, 2, 3 }, (int[]) { 4, 5, 6 }, (int[]) { 7, 8, 9 } };
    int target = 13, ans = minFallingPathSum(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *grid[] = { (int[]) { 7 } };
    int target = 7, ans = minFallingPathSum(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}