/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/1 下午7:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1557.c"

START_TEST(test_official_1) {
    int len, n = 6;
    int arr[][2] = { { 0, 1 }, { 0, 2 }, { 2, 5 }, { 3, 4 }, { 4, 2 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3], arr[4] };
    int target[] = { 0, 3 }, *ans = findSmallestSetOfVertices(n, grid, sizeof(grid) / sizeof(grid[0]), NULL, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int len, n = 5;
    int arr[][2] = { { 0, 1 }, { 2, 1 }, { 3, 1 }, { 1, 4 }, { 2, 4 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3], arr[4] };
    int target[] = { 0, 2, 3 }, *ans = findSmallestSetOfVertices(n, grid, sizeof(grid) / sizeof(grid[0]), NULL, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}
