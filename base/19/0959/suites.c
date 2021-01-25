/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/25 下午1:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0959.c"

START_TEST(test_official_1) {
    char *grid[] = { " /", "/ " };
    int target = 2, ans = regionsBySlashes(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *grid[] = { " /", "  " };
    int target = 1, ans = regionsBySlashes(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *grid[] = { "\\/", "/\\" };
    int target = 4, ans = regionsBySlashes(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *grid[] = { "/\\", "\\/" };
    int target = 5, ans = regionsBySlashes(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    char *grid[] = { "//", "/ " };
    int target = 3, ans = regionsBySlashes(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}