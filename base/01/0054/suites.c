/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/15 下午1:41
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0054.c"

START_TEST(test_official_1) {
    int col = 3, *grid[] = { (int[]) { 1, 2, 3 }, (int[]) { 4, 5, 6 }, (int[]) { 7, 8, 9 } };
    int target[] = { 1, 2, 3, 6, 9, 8, 7, 4, 5 };

    int len, *ans = spiralOrder(grid, LEN(grid), &col, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int col = 4, *grid[] = { (int[]) { 1, 2, 3, 4 }, (int[]) { 5, 6, 7, 8 }, (int[]) { 9, 10, 11, 12 } };
    int target[] = { 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7 };

    int len, *ans = spiralOrder(grid, LEN(grid), &col, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}