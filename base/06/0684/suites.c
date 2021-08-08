/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/13 上午11:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0684.c"

START_TEST(test_official_1) {
    int arr[][2] = { { 1, 2 }, { 1, 3 }, { 2, 3 } };
    int *grid[]  = { arr[0], arr[1], arr[2] };
    int target[] = { 2, 3 };
    int len, *ans = findRedundantConnection(grid, sizeof(grid) / sizeof(grid[0]), NULL, &len);

    ck_assert_int_eq(len, 2);
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int arr[][2] = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 4 }, { 1, 5 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3], arr[4] };
    int target[] = { 1, 4 };
    int len, *ans = findRedundantConnection(grid, sizeof(grid) / sizeof(grid[0]), NULL, &len);

    ck_assert_int_eq(len, 2);
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}