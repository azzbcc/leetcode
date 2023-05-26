/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/5/26 08:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1091.c"

START_TEST(test_official_1) {
    int col = 2, *grid[] = { (int[]) { 0, 1 }, (int[]) { 1, 0 } };
    int target = 2, ans = shortestPathBinaryMatrix(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int col = 3, *grid[] = { (int[]) { 0, 0, 0 }, (int[]) { 1, 1, 0 }, (int[]) { 1, 1, 0 } };
    int target = 4, ans = shortestPathBinaryMatrix(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int col = 3, *grid[] = { (int[]) { 1, 0, 0 }, (int[]) { 1, 1, 0 }, (int[]) { 1, 1, 0 } };
    int target = -1, ans = shortestPathBinaryMatrix(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}