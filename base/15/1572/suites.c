/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/23 下午2:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1572.c"

START_TEST(test_official_1) {
    int *grid[] = { (int[]) { 1, 2, 3 }, (int[]) { 4, 5, 6 }, (int[]) { 7, 8, 9 } };
    int target = 25, ans = diagonalSum(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *grid[] = { (int[]) { 1, 1, 1, 1 }, (int[]) { 1, 1, 1, 1 }, (int[]) { 1, 1, 1, 1 }, (int[]) { 1, 1, 1, 1 } };
    int target = 8, ans = diagonalSum(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *grid[] = { (int[]) { 5 } };
    int target = 5, ans = diagonalSum(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}