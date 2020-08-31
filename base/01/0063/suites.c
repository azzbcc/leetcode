/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/24 下午5:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0063.c"

START_TEST(test_official) {
    int len = 3, arr[][3] = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
    int *grid[] = { arr[0], arr[1], arr[2] };
    int target = 2, ans = uniquePathsWithObstacles(grid, sizeof(grid) / sizeof(grid[0]), &len);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    int len = 1, arr[][1] = { { 0 }, { 1 } };
    int *grid[] = { arr[0], arr[1] };
    int target = 0, ans = uniquePathsWithObstacles(grid, sizeof(grid) / sizeof(grid[0]), &len);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}