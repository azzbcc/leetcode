/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/5 上午9:04
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0802.c"

START_TEST(test_official_1) {
    int col[]    = { 2, 2, 1, 1, 1, 0, 0 };
    int *grid[]  = { (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 5 }, (int[]) { 0 },
                    (int[]) { 5 },    (int[]) {},       (int[]) {} };
    int target[] = { 2, 4, 5, 6 };
    int len, *ans = eventualSafeNodes(grid, LEN(grid), col, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int col[]    = { 4, 2, 2, 2, 0 };
    int *grid[]  = { (int[]) { 1, 2, 3, 4 }, (int[]) { 1, 2 }, (int[]) { 3, 4 }, (int[]) { 0, 4 }, (int[]) {} };
    int target[] = { 4 };
    int len, *ans = eventualSafeNodes(grid, LEN(grid), col, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}