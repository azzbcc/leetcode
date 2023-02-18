/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/18 下午1:27
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1237.c"

static int add(int x, int y) {
    return x + y;
}
static int mul(int x, int y) {
    return x * y;
}
static int tle(int x, int y) {
    return x * y * y;
}

START_TEST(test_official_1) {
    int len = 0, *returnColumnSizes = NULL;
    int *target[] = { (int[]) { 1, 4 }, (int[]) { 2, 3 }, (int[]) { 3, 2 }, (int[]) { 4, 1 } };
    int **ans     = findSolution(add, 5, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int len = 0, *returnColumnSizes = NULL;
    int *target[] = { (int[]) { 1, 5 }, (int[]) { 5, 1 } };
    int **ans     = findSolution(mul, 5, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_tle) {
    int len = 0, *returnColumnSizes = NULL;
    int *target[] = { (int[]) { 1, 10 }, (int[]) { 4, 5 }, (int[]) { 25, 2 }, (int[]) { 100, 1 } };
    int **ans     = findSolution(tle, 100, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}