/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/9 上午11:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0039.c"

START_TEST(test_official_1) {
    int arr[] = { 2, 3, 6, 7 }, k = 7;
    int col[] = { 3, 1 }, target[][3] = { { 2, 2, 3 }, { 7 } };
    int len = 0, *returnColumnSizes = NULL;
    int **ans = combinationSum(arr, sizeof(arr) / sizeof(arr[0]), k, &len, &returnColumnSizes);

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
    int arr[] = { 2, 3, 5 }, k = 8;
    int col[] = { 4, 3, 2 }, target[][4] = { { 2, 2, 2, 2 }, { 2, 3, 3 }, { 3, 5 } };
    int len = 0, *returnColumnSizes = NULL;
    int **ans = combinationSum(arr, sizeof(arr) / sizeof(arr[0]), k, &len, &returnColumnSizes);

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