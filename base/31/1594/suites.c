/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/27 下午11:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1594.c"

START_TEST(test_official_1) {
    int len = 3, arr[][3] = { { -1, -2, -3 }, { -2, -3, -3 }, { -3, -3, -2 } };
    int *grid[] = { arr[0], arr[1], arr[2] };

    int target = -1, ans = maxProductPath(grid, sizeof(grid) / sizeof(grid[0]), &len);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int len = 3, arr[][3] = { { 1, -2, 1 }, { 1, -2, 1 }, { 3, -4, 1 } };
    int *grid[] = { arr[0], arr[1], arr[2] };

    int target = 8, ans = maxProductPath(grid, sizeof(grid) / sizeof(grid[0]), &len);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    int len = 2, arr[][2] = { { 1, 3 }, { 0, -4 } };
    int *grid[] = { arr[0], arr[1] };

    int target = 0, ans = maxProductPath(grid, sizeof(grid) / sizeof(grid[0]), &len);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_4) {
    int len = 4, arr[][4] = { { 1, 4, 4, 0 }, { -2, 0, 0, 1 }, { 1, -1, 1, 1 } };
    int *grid[] = { arr[0], arr[1], arr[2] };

    int target = 2, ans = maxProductPath(grid, sizeof(grid) / sizeof(grid[0]), &len);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed_1) {
    int len = 3, arr[][3] = { { -1, 3, 0 }, { 3, -2, 3 }, { -1, 1, -4 } };
    int *grid[] = { arr[0], arr[1], arr[2] };

    int target = 0, ans = maxProductPath(grid, sizeof(grid) / sizeof(grid[0]), &len);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed_2) {
    int len = 10, arr[][10] = { { 2, 1, 3, 0, -3, 3, -4, 4, 0, -4 },    { -4, -3, 2, 2, 3, -3, 1, -1, 1, -2 },
                                { -2, 0, -4, 2, 4, -3, -4, -1, 3, 4 },  { -1, 0, 1, 0, -3, 3, -2, -3, 1, 0 },
                                { 0, -1, -2, 0, -3, -4, 0, 3, -2, -2 }, { -4, -2, 0, -1, 0, -3, 0, 4, 0, -3 },
                                { -3, -4, 2, 1, 0, -4, 2, -4, -1, -3 }, { 3, -2, 0, -4, 1, 0, 1, -3, -1, -1 },
                                { 3, -4, 0, 2, 0, -2, 2, -4, -2, 4 },   { 0, 4, 0, -3, -4, 3, 3, -1, -2, -2 } };
    int *grid[] = { arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9] };

    int target = 19215865, ans = maxProductPath(grid, sizeof(grid) / sizeof(grid[0]), &len);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}
