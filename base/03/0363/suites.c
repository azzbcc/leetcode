/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/22 下午2:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0363.c"

START_TEST(test_official_1) {
    int k = 2, col = 3;
    int *grid[] = { (int[]) { 1, 0, 1 }, (int[]) { 0, -2, 3 } };
    int target = 2, ans = maxSumSubmatrix(grid, LEN(grid), &col, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int k = 3, col = 3;
    int *grid[] = { (int[]) { 2, 2, -1 } };
    int target = 3, ans = maxSumSubmatrix(grid, LEN(grid), &col, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}