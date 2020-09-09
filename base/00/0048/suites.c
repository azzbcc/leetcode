/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/9 上午11:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0048.c"

START_TEST(test_official_1) {
    int arr[][3]    = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    int target[][3] = { { 7, 4, 1 }, { 8, 5, 2 }, { 9, 6, 3 } };
    int *grid[]     = { arr[0], arr[1], arr[2] };

    rotate(grid, sizeof(grid) / sizeof(grid[0]), NULL);

    ck_assert_mem_eq(arr, target, sizeof(arr));
}

START_TEST(test_official_2) {
    int arr[][4]    = { { 5, 1, 9, 11 }, { 2, 4, 8, 10 }, { 13, 3, 6, 7 }, { 15, 14, 12, 16 } };
    int target[][4] = { { 15, 13, 2, 5 }, { 14, 3, 4, 1 }, { 12, 6, 8, 9 }, { 16, 7, 10, 11 } };
    int *grid[]     = { arr[0], arr[1], arr[2], arr[3] };

    rotate(grid, sizeof(grid) / sizeof(grid[0]), NULL);

    ck_assert_mem_eq(arr, target, sizeof(arr));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}