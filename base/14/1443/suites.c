/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/26 下午6:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1443.c"

START_TEST(test_official_1) {
    int edges[][2]  = { { 0, 1 }, { 0, 2 }, { 1, 4 }, { 1, 5 }, { 2, 3 }, { 2, 6 } };
    bool hasApple[] = { false, false, true, false, true, true, false };
    int *grid[sizeof(edges) / sizeof(edges[0])], len = 2;
    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); grid[i] = edges[i], ++i) {}
    int target = 8, ans = minTime(sizeof(edges) / sizeof(edges[0]) + 1, grid, sizeof(grid) / sizeof(grid[0]), &len,
                                  hasApple, sizeof(hasApple) / sizeof(hasApple[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int edges[][2]  = { { 0, 1 }, { 0, 2 }, { 1, 4 }, { 1, 5 }, { 2, 3 }, { 2, 6 } };
    bool hasApple[] = { false, false, true, false, false, true, false };
    int *grid[sizeof(edges) / sizeof(edges[0])], len = 2;
    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); grid[i] = edges[i], ++i) {}
    int target = 6, ans = minTime(sizeof(edges) / sizeof(edges[0]) + 1, grid, sizeof(grid) / sizeof(grid[0]), &len,
                                  hasApple, sizeof(hasApple) / sizeof(hasApple[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    int edges[][2]  = { { 0, 1 }, { 0, 2 }, { 1, 4 }, { 1, 5 }, { 2, 3 }, { 2, 6 } };
    bool hasApple[] = { false, false, false, false, false, false, false };
    int *grid[sizeof(edges) / sizeof(edges[0])], len = 2;
    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); grid[i] = edges[i], ++i) {}
    int target = 0, ans = minTime(sizeof(edges) / sizeof(edges[0]) + 1, grid, sizeof(grid) / sizeof(grid[0]), &len,
                                  hasApple, sizeof(hasApple) / sizeof(hasApple[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    int edges[][2]  = { { 0, 2 }, { 0, 3 }, { 1, 2 } };
    bool hasApple[] = { false, true, false, false };
    int *grid[sizeof(edges) / sizeof(edges[0])], len = 2;
    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); grid[i] = edges[i], ++i) {}
    int target = 4, ans = minTime(sizeof(edges) / sizeof(edges[0]) + 1, grid, sizeof(grid) / sizeof(grid[0]), &len,
                                  hasApple, sizeof(hasApple) / sizeof(hasApple[0]));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}
