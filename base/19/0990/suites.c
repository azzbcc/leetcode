/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/11 下午9:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0990.c"

START_TEST(test_official_1) {
    char *grid[] = { "a==b", "b!=a" };
    bool target = false, ans = equationsPossible(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *grid[] = { "b==a", "a==b" };
    bool target = true, ans = equationsPossible(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *grid[] = { "a==b", "b==c", "a==c" };
    bool target = true, ans = equationsPossible(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *grid[] = { "a==b", "b!=c", "c==a" };
    bool target = false, ans = equationsPossible(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    char *grid[] = { "c==c", "b==d", "x!=z" };
    bool target = true, ans = equationsPossible(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}