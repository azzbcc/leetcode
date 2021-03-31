/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/31 下午1:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0090.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 2 };
    int len = 0, *returnColumnSizes = NULL;
    int col[]       = { 0, 1, 2, 3, 1, 2 };
    int target[][3] = { {}, { 1 }, { 1, 2 }, { 1, 2, 2 }, { 2 }, { 2, 2 } };
    int **ans       = subsetsWithDup(arr, sizeof(arr) / sizeof(arr[0]), &len, &returnColumnSizes);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(col[i], returnColumnSizes[i]);
        ck_assert_mem_eq(ans[i], target[i], col[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int arr[] = { 0 };
    int len = 0, *returnColumnSizes = NULL;
    int col[]       = { 0, 1 };
    int target[][3] = { {}, { 0 } };
    int **ans       = subsetsWithDup(arr, sizeof(arr) / sizeof(arr[0]), &len, &returnColumnSizes);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(col[i], returnColumnSizes[i]);
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