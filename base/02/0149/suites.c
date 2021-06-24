/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/24 下午2:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0149.c"

START_TEST(test_official_1) {
    int *points[] = { (int[]) { 1, 1 }, (int[]) { 2, 2 }, (int[]) { 3, 3 } };
    int target = 3, ans = maxPoints(points, LEN(points), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *points[] = { (int[]) { 1, 1 }, (int[]) { 3, 2 }, (int[]) { 5, 3 },
                      (int[]) { 4, 1 }, (int[]) { 2, 3 }, (int[]) { 1, 4 } };
    int target = 4, ans = maxPoints(points, LEN(points), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int *points[] = { (int[]) { 0, 0 } };
    int target = 1, ans = maxPoints(points, LEN(points), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int *points[] = { (int[]) { 4, 5 }, (int[]) { 4, -1 }, (int[]) { 4, 0 } };
    int target = 3, ans = maxPoints(points, LEN(points), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}