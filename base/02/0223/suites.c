/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/30 下午5:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0223.c"

START_TEST(test_official_1) {
    int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
    int target = 45, ans = computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2;
    int target = 16, ans = computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}