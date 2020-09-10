/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/10 上午11:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0040.c"

START_TEST(test_official_1) {
    int arr[] = { 10, 1, 2, 7, 6, 1, 5 }, k = 8;
    int col[] = { 3, 3, 2, 2 }, target[][3] = { { 1, 1, 6 }, { 1, 2, 5 }, { 1, 7 }, { 2, 6 } };
    int len = 0, *returnColumnSizes = NULL;
    int **ans = combinationSum2(arr, sizeof(arr) / sizeof(arr[0]), k, &len, &returnColumnSizes);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col[i]);
        ck_assert_mem_eq(ans[i], target[i], col[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int arr[] = { 2, 5, 2, 1, 2 }, k = 5;
    int col[] = { 3, 1 }, target[][3] = { { 1, 2, 2 }, { 5 } };
    int len = 0, *returnColumnSizes = NULL;
    int **ans = combinationSum2(arr, sizeof(arr) / sizeof(arr[0]), k, &len, &returnColumnSizes);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col[i]);
        ck_assert_mem_eq(ans[i], target[i], col[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}