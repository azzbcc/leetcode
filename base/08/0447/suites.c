/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/19 下午6:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0447.c"

START_TEST(test_official_1) {
    int *points[] = { (int[]) { 0, 0 }, (int[]) { 1, 0 }, (int[]) { 2, 0 } };
    int target = 2, ans = numberOfBoomerangs(points, LEN(points), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *points[] = { (int[]) { 1, 1 }, (int[]) { 2, 2 }, (int[]) { 3, 3 } };
    int target = 2, ans = numberOfBoomerangs(points, LEN(points), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *points[] = { (int[]) { 1, 1 } };
    int target = 0, ans = numberOfBoomerangs(points, LEN(points), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}