/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/25 上午10:56
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0240.c"

START_TEST(test_official_1) {
    int key = 5, col = 5;
    int *grid[] = { (int[]) { 1, 4, 7, 11, 15 }, (int[]) { 2, 5, 8, 12, 19 }, (int[]) { 3, 6, 9, 16, 22 },
                    (int[]) { 10, 13, 14, 17, 24 }, (int[]) { 18, 21, 23, 26, 30 } };
    bool target = true, ans = searchMatrix(grid, LEN(grid), &col, key);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int key = 20, col = 5;
    int *grid[] = { (int[]) { 1, 4, 7, 11, 15 }, (int[]) { 2, 5, 8, 12, 19 }, (int[]) { 3, 6, 9, 16, 22 },
                    (int[]) { 10, 13, 14, 17, 24 }, (int[]) { 18, 21, 23, 26, 30 } };
    bool target = false, ans = searchMatrix(grid, LEN(grid), &col, key);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}