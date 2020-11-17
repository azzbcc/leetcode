/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/15 上午11:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0037.c"

START_TEST(test_official) {
    char sudoku[][10] = { "53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1",
                          "7...2...6", ".6....28.", "...419..5", "....8..79" };
    char *grid[]      = {
        sudoku[0], sudoku[1], sudoku[2], sudoku[3], sudoku[4], sudoku[5], sudoku[6], sudoku[7], sudoku[8]
    };
    char target[][10] = { "534678912", "672195348", "198342567", "859761423", "426853791",
                          "713924856", "961537284", "287419635", "345286179" };

    solveSudoku(grid, LEN(grid), NULL);

    for (int i = 0; i < LEN(target); ++i) {
        ck_assert_str_eq(target[i], sudoku[i]);
    }
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}