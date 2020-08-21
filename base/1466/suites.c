/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/21 下午5:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1466.c"

START_TEST(test_official_1) {
    int n = 6, len = 2;
    int arr[][2] = { { 0, 1 }, { 1, 3 }, { 2, 3 }, { 4, 0 }, { 4, 5 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3], arr[4] };
    int target = 3, ans = minReorder(n, grid, sizeof(grid) / sizeof(grid[0]), &len);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int n = 5, len = 2;
    int arr[][2] = { { 1, 0 }, { 1, 2 }, { 3, 2 }, { 3, 4 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3] };
    int target = 2, ans = minReorder(n, grid, sizeof(grid) / sizeof(grid[0]), &len);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    int n = 3, len = 2;
    int arr[][2] = { { 1, 0 }, { 2, 0 } };
    int *grid[]  = { arr[0], arr[1] };
    int target = 0, ans = minReorder(n, grid, sizeof(grid) / sizeof(grid[0]), &len);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}
