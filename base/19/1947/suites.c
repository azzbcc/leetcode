/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/3 上午11:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1947.c"

START_TEST(test_official_1) {
    int col         = 3;
    int *students[] = { (int[]) { 1, 1, 0 }, (int[]) { 1, 0, 1 }, (int[]) { 0, 0, 1 } };
    int *mentors[]  = { (int[]) { 1, 0, 0 }, (int[]) { 0, 0, 1 }, (int[]) { 1, 1, 0 } };
    int target = 8, ans = maxCompatibilitySum(students, LEN(students), &col, mentors, LEN(mentors), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int col         = 2;
    int *students[] = { (int[]) { 0, 0 }, (int[]) { 0, 0 }, (int[]) { 0, 0 } };
    int *mentors[]  = { (int[]) { 1, 1 }, (int[]) { 1, 1 }, (int[]) { 1, 1 } };
    int target = 0, ans = maxCompatibilitySum(students, LEN(students), &col, mentors, LEN(mentors), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int col         = 6;
    int *students[] = { (int[]) { 0, 1, 0, 1, 1, 1 }, (int[]) { 1, 0, 0, 1, 0, 1 }, (int[]) { 1, 0, 1, 1, 0, 0 } };
    int *mentors[]  = { (int[]) { 1, 0, 0, 0, 0, 1 }, (int[]) { 0, 1, 0, 0, 1, 1 }, (int[]) { 0, 1, 0, 0, 1, 1 } };
    int target = 10, ans = maxCompatibilitySum(students, LEN(students), &col, mentors, LEN(mentors), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}