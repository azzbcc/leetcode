/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 20-8-16 下午16:56
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdlib.h>

#include "0733.c"

START_TEST(test_official) {
    int arr_len = 3, arr[][3] = { { 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1 } };
    int *grid[3]    = { arr[0], arr[1], arr[2] };
    int target[][3] = { { 2, 2, 2 }, { 2, 2, 0 }, { 2, 0, 1 } };
    int ans_len = 0, *returnColumnSizes = NULL;

    int **ans = floodFill(grid, sizeof(arr) / sizeof(arr[0]), &arr_len, 1, 1, 2, &ans_len, &returnColumnSizes);

    ck_assert_int_eq(ans_len, sizeof(target) / sizeof(target[0]));

    for (int i = 0; i < ans_len; ++i) {
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}