/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/16 上午11:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1610.c"

START_TEST(test_official_1) {
    int *points[] = { (int[]) { 2, 1 }, (int[]) { 2, 2 }, (int[]) { 3, 3 } }, angle = 90, location[] = { 1, 1 };
    int target = 3, ans = visiblePoints(points, LEN(points), NULL, angle, location, LEN(location));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *points[] = { (int[]) { 2, 1 }, (int[]) { 2, 2 }, (int[]) { 3, 4 }, (int[]) { 1, 1 } };
    int angle = 90, location[] = { 1, 1 };
    int target = 4, ans = visiblePoints(points, LEN(points), NULL, angle, location, LEN(location));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *points[] = { (int[]) { 1, 0 }, (int[]) { 2, 1 } }, angle = 13, location[] = { 1, 1 };
    int target = 1, ans = visiblePoints(points, LEN(points), NULL, angle, location, LEN(location));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int *points[] = { (int[]) { 2, 2 }, (int[]) { 3, 3 } }, angle = 0, location[] = { 1, 1 };
    int target = 2, ans = visiblePoints(points, LEN(points), NULL, angle, location, LEN(location));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}