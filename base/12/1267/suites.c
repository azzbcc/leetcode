/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/8/24 11:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1267.c"

START_TEST(test_offical_1) {
    int col = 2, *grid[] = { (int[]) { 1, 0 }, (int[]) { 0, 1 } };
    int target = 0, ans = countServers(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_offical_2) {
    int col = 2, *grid[] = { (int[]) { 1, 0 }, (int[]) { 1, 1 } };
    int target = 3, ans = countServers(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_offical_3) {
    int col     = 4,
        *grid[] = { (int[]) { 1, 1, 0, 0 }, (int[]) { 0, 0, 1, 0 }, (int[]) { 0, 0, 1, 0 }, (int[]) { 0, 0, 0, 1 } };
    int target = 4, ans = countServers(grid, LEN(grid), &col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_offical_1);
    tcase_add_test(t, test_offical_2);
    tcase_add_test(t, test_offical_3);
}