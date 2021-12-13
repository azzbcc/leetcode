/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/13 下午2:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0807.c"

START_TEST(test_official_1) {
    int *grid[] = { (int[]) { 3, 0, 8, 4 }, (int[]) { 2, 4, 5, 7 }, (int[]) { 9, 2, 6, 3 }, (int[]) { 0, 3, 1, 0 } };
    int target = 35, ans = maxIncreaseKeepingSkyline(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *grid[] = { (int[]) { 0, 0, 0 }, (int[]) { 0, 0, 0 }, (int[]) { 0, 0, 0 } };
    int target = 0, ans = maxIncreaseKeepingSkyline(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}