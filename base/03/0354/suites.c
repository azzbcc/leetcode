/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/4 上午11:53
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0354.c"

START_TEST(test_official) {
    int *grid[] = { (int[]) { 5, 4 }, (int[]) { 6, 4 }, (int[]) { 6, 7 }, (int[]) { 2, 3 } };
    int target = 3, ans = maxEnvelopes(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_01) {
    int *grid[] = {};
    int target = 0, ans = maxEnvelopes(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int *grid[] = { (int[]) { 1, 1 }, (int[]) { 2, 4 }, (int[]) { 3, 5 }, (int[]) { 4, 2 }, (int[]) { 4, 3 } };
    int target = 3, ans = maxEnvelopes(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_02) {
    int *grid[] = { (int[]) { 30, 50 }, (int[]) { 12, 2 }, (int[]) { 3, 4 }, (int[]) { 12, 15 } };
    int target = 3, ans = maxEnvelopes(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_03) {
    int *grid[] = {
        (int[]) { 15, 8 },  (int[]) { 2, 20 },  (int[]) { 2, 14 },  (int[]) { 4, 17 },  (int[]) { 8, 19 },
        (int[]) { 8, 9 },   (int[]) { 5, 7 },   (int[]) { 11, 19 }, (int[]) { 8, 11 },  (int[]) { 13, 11 },
        (int[]) { 2, 13 },  (int[]) { 11, 19 }, (int[]) { 8, 11 },  (int[]) { 13, 11 }, (int[]) { 2, 13 },
        (int[]) { 11, 19 }, (int[]) { 16, 1 },  (int[]) { 18, 13 }, (int[]) { 14, 17 }, (int[]) { 18, 19 }
    };
    int target = 5, ans = maxEnvelopes(grid, LEN(grid), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_03);
    tcase_add_test(t, test_failed_02);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_failed_01);
    tcase_add_test(t, test_official);
}