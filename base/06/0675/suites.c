/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/23 上午10:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0675.c"

START_TEST(test_official_1) {
    int col       = 3;
    int *forest[] = { (int[]) { 1, 2, 3 }, (int[]) { 0, 0, 4 }, (int[]) { 7, 6, 5 } };
    int target = 6, ans = cutOffTree(forest, LEN(forest), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int col       = 3;
    int *forest[] = { (int[]) { 1, 2, 3 }, (int[]) { 0, 0, 0 }, (int[]) { 7, 6, 5 } };
    int target = -1, ans = cutOffTree(forest, LEN(forest), &col);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int col       = 3;
    int *forest[] = { (int[]) { 2, 3, 4 }, (int[]) { 0, 0, 5 }, (int[]) { 8, 7, 6 } };
    int target = 6, ans = cutOffTree(forest, LEN(forest), &col);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}