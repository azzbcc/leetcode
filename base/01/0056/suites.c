/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/7 下午2:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0056.c"

START_TEST(test_official_1) {
    int col = 2, *grid[] = { (int[]) { 1, 3 }, (int[]) { 2, 6 }, (int[]) { 8, 10 }, (int[]) { 15, 18 } };
    int *target[] = { (int[]) { 1, 6 }, (int[]) { 8, 10 }, (int[]) { 15, 18 } };
    int len, *returnColumnSizes;
    int **ans = merge(grid, LEN(grid), &col, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col);
        ck_assert_mem_eq(ans[i], target[i], col * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

START_TEST(test_official_2) {
    int col = 2, *grid[] = { (int[]) { 1, 4 }, (int[]) { 4, 5 } };
    int *target[] = { (int[]) { 1, 5 } };
    int len, *returnColumnSizes;
    int **ans = merge(grid, LEN(grid), &col, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col);
        ck_assert_mem_eq(ans[i], target[i], col * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}