/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 20-7-23 下午8:11
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>

#include "0064.c"

START_TEST(test_official) {
    int len      = 3;
    int arr[][3] = { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } }, target = 7;
    int *grid[3] = { NULL };

    for (int i = 0; i < 3; ++i) {
        grid[i] = arr[i];
    }

    int res = minPathSum(grid, sizeof(arr) / sizeof(arr[0]), &len);

    ck_assert_msg(res == target, "error, except %d but got %d on minPathSum([[1, 3, 1], [1, 5, 1], [4, 2, 1]]).",
                  target, res);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}