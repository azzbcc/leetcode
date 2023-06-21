/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/21 16:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "lcp_41.c"

START_TEST(test_official_1) {
    char *board[] = { "....X.", "....X.", "XOOO..", "......", "......" };
    int target = 3, ans = flipChess(board, LEN(board));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *board[] = { ".X.", ".O.", "XO." };
    int target = 2, ans = flipChess(board, LEN(board));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *board[] = { ".......", ".......", ".......", "X......", ".O.....", "..O....", "....OOX" };
    int target = 4, ans = flipChess(board, LEN(board));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}