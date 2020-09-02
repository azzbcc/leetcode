/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/2 下午1:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0815.c"

START_TEST(test_official) {
    int cols[]   = { 3, 3 };
    int arr[][3] = { { 1, 2, 7 }, { 3, 6, 7 } }, S = 1, T = 6;
    int *grid[] = { arr[0], arr[1] };

    int target = 2, ans = numBusesToDestination(grid, sizeof(grid) / sizeof(grid[0]), cols, S, T);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}