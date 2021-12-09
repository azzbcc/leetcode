/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/9 上午11:05
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0794.c"

START_TEST(test_official_1) {
    char *board[] = { "O  ", "   ", "   " };
    bool target = false, ans = validTicTacToe(board, LEN(board));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *board[] = { "XOX", " X ", "   " };
    bool target = false, ans = validTicTacToe(board, LEN(board));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *board[] = { "XXX", "   ", "OOO" };
    bool target = false, ans = validTicTacToe(board, LEN(board));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *board[] = { "XOX", "O O", "XOX" };
    bool target = true, ans = validTicTacToe(board, LEN(board));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    char *board[] = { "XXX", "XOO", "OO " };
    bool target = false, ans = validTicTacToe(board, LEN(board));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}