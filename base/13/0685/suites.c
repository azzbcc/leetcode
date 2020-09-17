/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/17 下午4:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0685.c"

START_TEST(test_official_1) {
    int arr[][2] = { { 1, 2 }, { 1, 3 }, { 2, 3 } };
    int *grid[]  = { arr[0], arr[1], arr[2] };
    int target[] = { 2, 3 };
    int len, *ans = findRedundantDirectedConnection(grid, sizeof(grid) / sizeof(grid[0]), NULL, &len);

    ck_assert_int_eq(len, 2);
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}
START_TEST(test_official_2) {
    int arr[][2] = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 1 }, { 1, 5 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3], arr[4] };
    int target[] = { 4, 1 };
    int len, *ans = findRedundantDirectedConnection(grid, sizeof(grid) / sizeof(grid[0]), NULL, &len);

    ck_assert_int_eq(len, 2);
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}
START_TEST(test_failed_1) {
    int arr[][2] = { { 2, 1 }, { 3, 1 }, { 4, 2 }, { 1, 4 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3] };
    int target[] = { 2, 1 };
    int len, *ans = findRedundantDirectedConnection(grid, sizeof(grid) / sizeof(grid[0]), NULL, &len);

    ck_assert_int_eq(len, 2);
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}
START_TEST(test_failed_2) {
    int arr[][2] = { { 4, 2 }, { 1, 5 }, { 5, 2 }, { 5, 3 }, { 2, 4 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3], arr[4] };
    int target[] = { 4, 2 };
    int len, *ans = findRedundantDirectedConnection(grid, sizeof(grid) / sizeof(grid[0]), NULL, &len);

    ck_assert_int_eq(len, 2);
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}
START_TEST(test_failed_3) {
    int arr[][2] = { { 5, 2 }, { 5, 1 }, { 3, 1 }, { 3, 4 }, { 3, 5 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3], arr[4] };
    int target[] = { 3, 1 };
    int len, *ans = findRedundantDirectedConnection(grid, sizeof(grid) / sizeof(grid[0]), NULL, &len);

    ck_assert_int_eq(len, 2);
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}
START_TEST(test_failed_4) {
    int arr[][2] = { { 4, 1 }, { 4, 5 }, { 2, 4 }, { 5, 3 }, { 2, 1 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3], arr[4] };
    int target[] = { 2, 1 };
    int len, *ans = findRedundantDirectedConnection(grid, sizeof(grid) / sizeof(grid[0]), NULL, &len);

    ck_assert_int_eq(len, 2);
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_4);
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}