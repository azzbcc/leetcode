/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/30 上午11:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0463.c"

START_TEST(test_official) {
    int len      = 4;
    int arr[][4] = { { 0, 1, 0, 0 }, { 1, 1, 1, 0 }, { 0, 1, 0, 0 }, { 1, 1, 0, 0 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3] };

    int target = 16, ans = islandPerimeter(grid, LEN(grid), &len);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}