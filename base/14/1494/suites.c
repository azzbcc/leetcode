/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/16 13:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1494.c"

START_TEST(test_official_1) {
    int n = 4, k = 2;
    int *relations[] = { (int[]) { 2, 1 }, (int[]) { 3, 1 }, (int[]) { 1, 4 } };
    int target = 3, ans = minNumberOfSemesters(n, relations, LEN(relations), NULL, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 5, k = 2;
    int *relations[] = { (int[]) { 2, 1 }, (int[]) { 3, 1 }, (int[]) { 4, 1 }, (int[]) { 1, 5 } };
    int target = 4, ans = minNumberOfSemesters(n, relations, LEN(relations), NULL, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n = 11, k = 2;
    int *relations[] = {};
    int target = 6, ans = minNumberOfSemesters(n, relations, LEN(relations), NULL, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle) {
    int n = 15, k = 12;
    int *relations[] = { (int[]) { 12, 11 } };
    int target = 2, ans = minNumberOfSemesters(n, relations, LEN(relations), NULL, k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}