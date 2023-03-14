/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/14 下午2:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1605.c"

static void run(int row[], size_t rowSize, int col[], size_t colSize) {
    int rowCopy[rowSize], colCopy[colSize];
    int len = 0, *returnColumnSizes = NULL, **ans;

    memcpy(rowCopy, row, rowSize * sizeof(int));
    memcpy(colCopy, col, colSize * sizeof(int));
    ans = restoreMatrix(rowCopy, rowSize, colCopy, colSize, &len, &returnColumnSizes);

    ck_assert_int_eq(len, rowSize);
    memset(rowCopy, 0, sizeof(rowCopy));
    memset(colCopy, 0, sizeof(colCopy));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], colSize);
        for (int j = 0; j < colSize; ++j) {
            rowCopy[i] += ans[i][j], colCopy[j] += ans[i][j];
        }
        free(ans[i]);
    }
    ck_assert_mem_eq(rowCopy, row, sizeof(rowCopy));
    ck_assert_mem_eq(colCopy, col, sizeof(colCopy));
    free(returnColumnSizes);
    free(ans);
}

START_TEST(test_official_1) {
    int rowSum[] = { 3, 8 }, colSum[] = { 4, 7 };
    run(rowSum, LEN(rowSum), colSum, LEN(colSum));
}

START_TEST(test_official_2) {
    int rowSum[] = { 5, 7, 10 }, colSum[] = { 8, 6, 8 };
    run(rowSum, LEN(rowSum), colSum, LEN(colSum));
}

START_TEST(test_official_3) {
    int rowSum[] = { 14, 9 }, colSum[] = { 6, 9, 8 };
    run(rowSum, LEN(rowSum), colSum, LEN(colSum));
}

START_TEST(test_official_4) {
    int rowSum[] = { 1, 0 }, colSum[] = { 1 };
    run(rowSum, LEN(rowSum), colSum, LEN(colSum));
}

START_TEST(test_official_5) {
    int rowSum[] = { 0 }, colSum[] = { 0 };
    run(rowSum, LEN(rowSum), colSum, LEN(colSum));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}