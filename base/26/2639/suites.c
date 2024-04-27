/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/27 17:27
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2639.c"

START_TEST(test_official_1) {
    int len, col = 1;
    int *grid[]  = { (int[]) { 1 }, (int[]) { 22 }, (int[]) { 333 } };
    int target[] = { 3 }, *ans = findColumnWidth(grid, LEN(grid), &col, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int len, col = 3;
    int *grid[]  = { (int[]) { -15, 1, 3 }, (int[]) { 15, 7, 12 }, (int[]) { 5, 6, -2 } };
    int target[] = { 3, 1, 2 }, *ans = findColumnWidth(grid, LEN(grid), &col, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}