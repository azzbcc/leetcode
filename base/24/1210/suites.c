/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/19 下午4:48
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1210.c"

START_TEST(test_official_1) {
    int *grid[] = { (int[]) { 0, 0, 0, 0, 0, 1 }, (int[]) { 1, 1, 0, 0, 1, 0 }, (int[]) { 0, 0, 0, 0, 1, 1 },
                    (int[]) { 0, 0, 1, 0, 1, 0 }, (int[]) { 0, 1, 1, 0, 0, 0 }, (int[]) { 0, 1, 1, 0, 0, 0 } };
    int target = 11, ans = minimumMoves(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *grid[] = { (int[]) { 0, 0, 1, 1, 1, 1 }, (int[]) { 0, 0, 0, 0, 1, 1 }, (int[]) { 1, 1, 0, 0, 0, 1 },
                    (int[]) { 1, 1, 1, 0, 0, 1 }, (int[]) { 1, 1, 1, 0, 0, 1 }, (int[]) { 1, 1, 1, 0, 0, 0 } };
    int target = 9, ans = minimumMoves(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
//    tcase_add_test(t, test_official_2);
}