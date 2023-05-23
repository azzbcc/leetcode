/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/5/23 15:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1090.c"

START_TEST(test_official_1) {
    int values[] = { 5, 4, 3, 2, 1 }, labels[] = { 1, 1, 2, 2, 3 }, numWanted = 3, useLimit = 1;
    int target = 9, ans = largestValsFromLabels(values, LEN(values), labels, LEN(labels), numWanted, useLimit);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int values[] = { 5, 4, 3, 2, 1 }, labels[] = { 1, 3, 3, 3, 2 }, numWanted = 3, useLimit = 2;
    int target = 12, ans = largestValsFromLabels(values, LEN(values), labels, LEN(labels), numWanted, useLimit);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int values[] = { 9, 8, 8, 7, 6 }, labels[] = { 0, 0, 0, 1, 1 }, numWanted = 3, useLimit = 1;
    int target = 16, ans = largestValsFromLabels(values, LEN(values), labels, LEN(labels), numWanted, useLimit);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}