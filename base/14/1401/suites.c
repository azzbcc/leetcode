/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/25 16:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1401.c"

START_TEST(test_official_1) {
    int radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1;
    ck_assert_int_eq(true, checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2));
}

START_TEST(test_official_2) {
    int radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1;
    ck_assert_int_eq(false, checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2));
}

START_TEST(test_official_3) {
    int radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1;
    ck_assert_int_eq(true, checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}