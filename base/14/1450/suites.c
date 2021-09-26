/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/26 下午8:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1450.c"

START_TEST(test_official_1) {
    int startTime[] = { 1, 2, 3 }, endTime[] = { 3, 2, 7 }, queryTime = 4;
    int target = 1, ans = busyStudent(startTime, LEN(startTime), endTime, LEN(endTime), queryTime);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int startTime[] = { 4 }, endTime[] = { 4 }, queryTime = 4;
    int target = 1, ans = busyStudent(startTime, LEN(startTime), endTime, LEN(endTime), queryTime);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int startTime[] = { 4 }, endTime[] = { 4 }, queryTime = 5;
    int target = 0, ans = busyStudent(startTime, LEN(startTime), endTime, LEN(endTime), queryTime);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int startTime[] = { 1, 1, 1, 1 }, endTime[] = { 1, 3, 2, 4 }, queryTime = 7;
    int target = 0, ans = busyStudent(startTime, LEN(startTime), endTime, LEN(endTime), queryTime);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int startTime[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 }, endTime[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10 }, queryTime = 5;
    int target = 5, ans = busyStudent(startTime, LEN(startTime), endTime, LEN(endTime), queryTime);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}