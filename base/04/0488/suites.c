/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/9 上午11:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0488.c"

START_TEST(test_official_1) {
    char *board = "WRRBBW", *hand = "RB";
    int target = -1, ans = findMinStep(board, hand);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *board = "WWRRBBWW", *hand = "WRBRW";
    int target = 2, ans = findMinStep(board, hand);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *board = "G", *hand = "GGGGG";
    int target = 2, ans = findMinStep(board, hand);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *board = "RBYYBBRRB", *hand = "YRBGB";
    int target = 3, ans = findMinStep(board, hand);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    char *board = "RRYGGYYRRYGGYYRR", *hand = "GGBBB";
    int target = 5, ans = findMinStep(board, hand);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    char *board = "RRWWRRW", *hand = "WR";
    int target = -1, ans = findMinStep(board, hand);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    char *board = "RRWWRRBBRR", *hand = "WB";
    int target = 2, ans = findMinStep(board, hand);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_3) {
    char *board = "WWRRBBWW", *hand = "WRBRW";
    int target = 2, ans = findMinStep(board, hand);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle) {
    char *board = "RRYGGYYRRYYGGYRR", *hand = "GGBBB";
    int target = 5, ans = findMinStep(board, hand);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}