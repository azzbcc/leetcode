/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/28 16:01
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2050.c"

START_TEST(test_official_1) {
    int n = 3, time[] = { 3, 2, 5 };
    int *relations[] = { (int[]) { 1, 3 }, (int[]) { 2, 3 } };
    int target = 8, ans = minimumTime(n, relations, LEN(relations), NULL, time, LEN(time));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 5, time[] = { 1, 2, 3, 4, 5 };
    int *relations[] = { (int[]) { 1, 5 }, (int[]) { 2, 5 }, (int[]) { 3, 5 }, (int[]) { 3, 4 }, (int[]) { 4, 5 } };
    int target = 12, ans = minimumTime(n, relations, LEN(relations), NULL, time, LEN(time));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int n = 1, time[] = { 1 };
    int *relations[] = {};
    int target = 1, ans = minimumTime(n, relations, LEN(relations), NULL, time, LEN(time));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}