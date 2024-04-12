/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/12 14:39
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2923.c"

START_TEST(test_official_1) {
    int *grid[] = { (int[]) { 0, 1 }, (int[]) { 0, 0 } };
    int target = 0, ans = findChampion(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *grid[] = { (int[]) { 0, 0, 1 }, (int[]) { 1, 0, 1 }, (int[]) { 0, 0, 0 } };
    int target = 1, ans = findChampion(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}