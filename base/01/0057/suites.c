/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/4 上午13:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0057.c"

START_TEST(test_official_1) {
    int intervals[][2] = { { 1, 3 }, { 6, 9 } }, newInterval[] = { 2, 5 };
    int *grid[] = { intervals[0], intervals[1] };
    int len, *returnColumnSizes = NULL, target[][2] = { { 1, 5 }, { 6, 9 } };
    int **ans = insert(grid, LEN(grid), NULL, newInterval, LEN(newInterval), &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], LEN(target[i]));
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int intervals[][2] = { { 1, 2 }, { 3, 5 }, { 6, 7 }, { 8, 10 }, { 12, 16 } }, newInterval[] = { 4, 8 };
    int *grid[] = { intervals[0], intervals[1], intervals[2], intervals[3], intervals[4] };
    int len, *returnColumnSizes = NULL, target[][2] = { { 1, 2 }, { 3, 10 }, { 12, 16 } };
    int **ans = insert(grid, LEN(grid), NULL, newInterval, LEN(newInterval), &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], LEN(target[i]));
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_own) {
    int intervals[][2] = { { 1, 2 }, { 6, 7 }, { 8, 9 } }, newInterval[] = { 4, 5 };
    int *grid[] = { intervals[0], intervals[1], intervals[2] };
    int len, *returnColumnSizes = NULL, target[][2] = { { 1, 2 }, { 4, 5 }, { 6, 7 }, { 8, 9 } };
    int **ans = insert(grid, LEN(grid), NULL, newInterval, LEN(newInterval), &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], LEN(target[i]));
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_failed) {
    int newInterval[] = { 5, 7 }, *grid[] = {};
    int len, *returnColumnSizes = NULL, target[][2] = { { 5, 7 } };
    int **ans = insert(grid, LEN(grid), NULL, newInterval, LEN(newInterval), &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], LEN(target[i]));
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}