/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/14 上午11:56
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "lcs_03.c"

START_TEST(test_official_1) {
    char *grid[] = { "110", "231", "221" };
    int target = 1, ans = largestArea(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *grid[] = { "11111100000", "21243101111", "21224101221", "11111101111" };
    int target = 3, ans = largestArea(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    char *grid[] = { "111111", "212031", "212241", "111111" };
    int target = 1, ans = largestArea(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    char *grid[] = { "113415514", "124112542", "313225220", "253354005", "352014331",
                     "304514425", "553313413", "532352143", "220340311", "245210141" };
    int target = 2, ans = largestArea(grid, LEN(grid));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}