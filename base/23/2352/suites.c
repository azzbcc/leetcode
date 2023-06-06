/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/6 12:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2352.c"

START_TEST(test_official_1) {
    int *grid[] = { (int[]) { 3, 2, 1 }, (int[]) { 1, 7, 6 }, (int[]) { 2, 7, 7 } };
    int target = 1, ans = equalPairs(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *grid[] = { (int[]) { 3, 1, 2, 2 }, (int[]) { 1, 4, 4, 5 }, (int[]) { 2, 4, 2, 2 }, (int[]) { 2, 4, 2, 2 } };
    int target = 3, ans = equalPairs(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}