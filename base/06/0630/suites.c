/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/14 上午11:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0630.c"

START_TEST(test_official_1) {
    int *courses[] = { (int[]) { 100, 200 }, (int[]) { 200, 1300 }, (int[]) { 1000, 1250 }, (int[]) { 2000, 3200 } };
    int target = 3, ans = scheduleCourse(courses, LEN(courses), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *courses[] = { (int[]) { 1, 2 } };
    int target = 1, ans = scheduleCourse(courses, LEN(courses), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *courses[] = { (int[]) { 3, 2 }, (int[]) { 4, 3 } };
    int target = 0, ans = scheduleCourse(courses, LEN(courses), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}