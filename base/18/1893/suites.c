/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/23 上午11:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1893.c"

START_TEST(test_official_1) {
    int *grid[] = { (int[]) { 1, 2 }, (int[]) { 3, 4 }, (int[]) { 5, 6 } };
    int left = 2, right = 5;
    bool target = true, ans = isCovered(grid, LEN(grid), NULL, left, right);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *grid[] = { (int[]) { 1, 10 }, (int[]) { 10, 20 } };
    int left = 21, right = 21;
    bool target = false, ans = isCovered(grid, LEN(grid), NULL, left, right);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}