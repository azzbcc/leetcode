/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/7 上午10:11
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1034.c"

START_TEST(test_official_1) {
    int len = 0, *returnColumnSizes = NULL;
    int grid_col = 2, row = 0, col = 0, color = 3;
    int *grid[]   = { (int[]) { 1, 1 }, (int[]) { 1, 2 } };
    int *target[] = { (int[]) { 3, 3 }, (int[]) { 3, 2 } };

    int **ans = colorBorder(grid, LEN(grid), &grid_col, row, col, color, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], grid_col);
        ck_assert_mem_eq(ans[i], target[i], grid_col * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int len = 0, *returnColumnSizes = NULL;
    int grid_col = 3, row = 0, col = 1, color = 3;
    int *grid[]   = { (int[]) { 1, 2, 2 }, (int[]) { 2, 3, 2 } };
    int *target[] = { (int[]) { 1, 3, 3 }, (int[]) { 2, 3, 3 } };

    int **ans = colorBorder(grid, LEN(grid), &grid_col, row, col, color, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], grid_col);
        ck_assert_mem_eq(ans[i], target[i], grid_col * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_3) {
    int len = 0, *returnColumnSizes = NULL;
    int grid_col = 3, row = 1, col = 1, color = 2;
    int *grid[]   = { (int[]) { 1, 1, 1 }, (int[]) { 1, 1, 1 }, (int[]) { 1, 1, 1 } };
    int *target[] = { (int[]) { 2, 2, 2 }, (int[]) { 2, 1, 2 }, (int[]) { 2, 2, 2 } };

    int **ans = colorBorder(grid, LEN(grid), &grid_col, row, col, color, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], grid_col);
        ck_assert_mem_eq(ans[i], target[i], grid_col * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}