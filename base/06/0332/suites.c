/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/27 上午13:28
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0332.c"

START_TEST(test_official_1) {
    int len, col = 2;
    char *arr[][2] = { { "MUC", "LHR" }, { "JFK", "MUC" }, { "SFO", "SJC" }, { "LHR", "SFO" } };
    char **grid[]  = { arr[0], arr[1], arr[2], arr[3] };
    char *target[] = { "JFK", "MUC", "LHR", "SFO", "SJC" };
    char **ans     = findItinerary(grid, sizeof(grid) / sizeof(grid[0]), &col, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len, col = 2;
    char *arr[][2] = { { "JFK", "SFO" }, { "JFK", "ATL" }, { "SFO", "ATL" }, { "ATL", "JFK" }, { "ATL", "SFO" } };
    char **grid[]  = { arr[0], arr[1], arr[2], arr[3], arr[4] };
    char *target[] = { "JFK", "ATL", "JFK", "SFO", "ATL", "SFO" };
    char **ans     = findItinerary(grid, sizeof(grid) / sizeof(grid[0]), &col, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_failed) {
    int len, col = 2;
    char *arr[][2] = { { "JFK", "KUL" }, { "JFK", "NRT" }, { "NRT", "JFK" } };
    char **grid[]  = { arr[0], arr[1], arr[2] };
    char *target[] = { "JFK", "NRT", "JFK", "KUL" };
    char **ans     = findItinerary(grid, sizeof(grid) / sizeof(grid[0]), &col, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}
