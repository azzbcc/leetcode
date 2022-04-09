/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/9 上午9:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0780.c"

START_TEST(test_official_1) {
    int sx = 1, sy = 1, tx = 3, ty = 5;
    bool target = true, ans = reachingPoints(sx, sy, tx, ty);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int sx = 1, sy = 1, tx = 2, ty = 2;
    bool target = false, ans = reachingPoints(sx, sy, tx, ty);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int sx = 1, sy = 1, tx = 1, ty = 1;
    bool target = true, ans = reachingPoints(sx, sy, tx, ty);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int sx = 3, sy = 3, tx = 12, ty = 9;
    bool target = true, ans = reachingPoints(sx, sy, tx, ty);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int sx = 1, sy = 8, tx = 4, ty = 15;
    bool target = false, ans = reachingPoints(sx, sy, tx, ty);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_3) {
    int sx = 4, sy = 2, tx = 2, ty = 4;
    bool target = false, ans = reachingPoints(sx, sy, tx, ty);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}