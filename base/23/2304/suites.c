/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/8 14:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2304.c"

START_TEST(test_official_1) {
    int col = 2, *grid[] = { (int[]) { 5, 3 }, (int[]) { 4, 0 }, (int[]) { 2, 1 } };
    int *moveCost[] = { (int[]) { 9, 8 },  (int[]) { 1, 5 }, (int[]) { 10, 12 },
                        (int[]) { 18, 6 }, (int[]) { 2, 4 }, (int[]) { 14, 3 } };
    int target = 17, ans = minPathCost(grid, LEN(grid), &col, moveCost, LEN(moveCost), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int col = 3, *grid[] = { (int[]) { 5, 1, 2 }, (int[]) { 4, 0, 3 } };
    int *moveCost[] = { (int[]) { 12, 10, 15 }, (int[]) { 20, 23, 8 }, (int[]) { 21, 7, 1 },
                        (int[]) { 8, 1, 13 },   (int[]) { 9, 10, 25 }, (int[]) { 5, 3, 2 } };
    int target = 6, ans = minPathCost(grid, LEN(grid), &col, moveCost, LEN(moveCost), &col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}