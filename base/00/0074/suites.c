/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/30 下午12:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0074.c"

START_TEST(test_official_1) {
    int key = 3, col = 4, *grid[] = { (int[]) { 1, 3, 5, 7 }, (int[]) { 10, 11, 16, 20 }, (int[]) { 23, 30, 34, 60 } };
    bool target = true, ans = searchMatrix(grid, LEN(grid), &col, key);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int key = 13, col = 4, *grid[] = { (int[]) { 1, 3, 5, 7 }, (int[]) { 10, 11, 16, 20 }, (int[]) { 23, 30, 34, 60 } };
    bool target = false, ans = searchMatrix(grid, LEN(grid), &col, key);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}