/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/18 12:10
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1254.c"

START_TEST(test_official_1) {
    int *grid[] = { (int[]) { 1, 1, 1, 1, 1, 1, 1, 0 }, (int[]) { 1, 0, 0, 0, 0, 1, 1, 0 },
                    (int[]) { 1, 0, 1, 0, 1, 1, 1, 0 }, (int[]) { 1, 0, 0, 0, 0, 1, 0, 1 },
                    (int[]) { 1, 1, 1, 1, 1, 1, 1, 0 } };
    int col = 8, target = 2, ans = closedIsland(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *grid[] = { (int[]) { 0, 0, 1, 0, 0 }, (int[]) { 0, 1, 0, 1, 0 }, (int[]) { 0, 1, 1, 1, 0 } };
    int col = 5, target = 1, ans = closedIsland(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *grid[] = { (int[]) { 1, 1, 1, 1, 1, 1, 1 }, (int[]) { 1, 0, 0, 0, 0, 0, 1 }, (int[]) { 1, 0, 1, 1, 1, 0, 1 },
                    (int[]) { 1, 0, 1, 0, 1, 0, 1 }, (int[]) { 1, 0, 1, 1, 1, 0, 1 }, (int[]) { 1, 0, 0, 0, 0, 0, 1 },
                    (int[]) { 1, 1, 1, 1, 1, 1, 1 } };
    int col = 7, target = 2, ans = closedIsland(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int *grid[] = { (int[]) { 0, 0, 1, 1, 0, 1, 0, 0, 1, 0 }, (int[]) { 1, 1, 0, 1, 1, 0, 1, 1, 1, 0 },
                    (int[]) { 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 }, (int[]) { 0, 1, 1, 0, 0, 0, 0, 1, 0, 1 },
                    (int[]) { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 }, (int[]) { 0, 1, 0, 1, 0, 1, 0, 1, 1, 1 },
                    (int[]) { 1, 0, 1, 0, 1, 1, 0, 0, 0, 1 }, (int[]) { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
                    (int[]) { 1, 1, 1, 0, 0, 1, 0, 1, 0, 1 }, (int[]) { 1, 1, 1, 0, 1, 1, 0, 1, 1, 0 } };
    int col = 10, target = 5, ans = closedIsland(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}