/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/31 下午12:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0841.c"

START_TEST(test_official_1) {
    int cols[]   = { 1, 1, 1, 0 };
    int arr[][1] = { { 1 }, { 2 }, { 3 }, {} };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3] };
    bool target = true, ans = canVisitAllRooms(grid, sizeof(grid) / sizeof(grid[0]), cols);

    ck_assert_int_eq(target, ans);
}
START_TEST(test_official_2) {
    int cols[]   = { 2, 3, 1, 1 };
    int arr[][3] = { { 1, 3 }, { 3, 0, 1 }, { 2 }, { 0 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3] };
    bool target = false, ans = canVisitAllRooms(grid, sizeof(grid) / sizeof(grid[0]), cols);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}