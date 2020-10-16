/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/16 下午1:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0036.c"

START_TEST(test_official_1) {
    char *board[] = { "53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1",
                      "7...2...6", ".6....28.", "...419..5", "....8..79" };

    bool target = true, ans = isValidSudoku(board, LEN(board), NULL);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    char *board[] = { "83..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1",
                      "7...2...6", ".6....28.", "...419..5", "....8..79" };

    bool target = false, ans = isValidSudoku(board, LEN(board), NULL);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}