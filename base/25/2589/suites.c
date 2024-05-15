/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/5/15 15:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2589.c"

START_TEST(test_official_1) {
    int *tasks[] = { (int[]) { 2, 3, 1 }, (int[]) { 4, 5, 1 }, (int[]) { 1, 5, 2 } };
    int target = 2, ans = findMinimumTime(tasks, LEN(tasks), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *tasks[] = { (int[]) { 1, 3, 2 }, (int[]) { 2, 5, 3 }, (int[]) { 5, 6, 2 } };
    int target = 4, ans = findMinimumTime(tasks, LEN(tasks), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}