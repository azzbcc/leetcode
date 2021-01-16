/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/15 上午11:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0947.c"

START_TEST(test_official_1) {
    int arr[][2] = { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 2 }, { 2, 1 }, { 2, 2 } }, *grid[LEN(arr)];
    for (int i = 0; i < LEN(arr); ++i) {
        grid[i] = arr[i];
    }
    int target = 5, ans = removeStones(grid, LEN(grid), NULL);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[][2] = { { 0, 0 }, { 0, 2 }, { 1, 1 }, { 2, 0 }, { 2, 2 } }, *grid[LEN(arr)];
    for (int i = 0; i < LEN(arr); ++i) {
        grid[i] = arr[i];
    }
    int target = 3, ans = removeStones(grid, LEN(grid), NULL);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[][2] = { { 0, 0 } }, *grid[LEN(arr)];
    for (int i = 0; i < LEN(arr); ++i) {
        grid[i] = arr[i];
    }
    int target = 0, ans = removeStones(grid, LEN(grid), NULL);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int arr[][2] = { { 0, 0 }, { 1, 1 }, { 0, 1 }, { 1, 0 } }, *grid[LEN(arr)];
    for (int i = 0; i < LEN(arr); ++i) {
        grid[i] = arr[i];
    }
    int target = 3, ans = removeStones(grid, LEN(grid), NULL);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}