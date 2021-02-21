/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/22 上午12:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0766.c"

START_TEST(test_official_1) {
    int col = 4, *grid[] = { (int[]) { 1, 2, 3, 4 }, (int[]) { 5, 1, 2, 3 }, (int[]) { 9, 5, 1, 2 } };
    bool target = true, ans = isToeplitzMatrix(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int col = 4, *grid[] = { (int[]) { 1, 2 }, (int[]) { 2, 2 } };
    bool target = false, ans = isToeplitzMatrix(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}