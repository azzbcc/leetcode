/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/21 下午5:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0329.c"

START_TEST(test_official_1) {
    int len = 3, arr[][3] = { { 9, 9, 4 }, { 6, 6, 8 }, { 2, 1, 1 } };
    int *grid[] = { arr[0], arr[1], arr[2] };
    int target = 4, ans = longestIncreasingPath(grid, sizeof(grid) / sizeof(grid[0]), &len);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int len = 3, arr[][3] = { { 3, 4, 5 }, { 3, 2, 6 }, { 2, 2, 1 } };
    int *grid[] = { arr[0], arr[1], arr[2] };
    int target = 4, ans = longestIncreasingPath(grid, sizeof(grid) / sizeof(grid[0]), &len);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}