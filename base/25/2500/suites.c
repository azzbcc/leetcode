/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/27 15:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2500.c"

START_TEST(test_official_1) {
    int col = 3, *grid[] = { (int[]) { 1, 2, 4 }, (int[]) { 3, 3, 1 } };
    int target = 8, ans = deleteGreatestValue(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int col = 1, *grid[] = { (int[]) { 10 } };
    int target = 10, ans = deleteGreatestValue(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}