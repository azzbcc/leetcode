/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/20 下午6:00
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0078.c"

START_TEST(test_official) {
    int arr[] = { 1, 2, 3 };
    int len = 0, *returnColumnSizes = NULL;
    int col[]       = { 0, 1, 1, 2, 1, 2, 2, 3 };
    int target[][3] = { {}, { 1 }, { 2 }, { 1, 2 }, { 3 }, { 1, 3 }, { 2, 3 }, { 1, 2, 3 } };
    int **ans       = subsets(arr, sizeof(arr) / sizeof(arr[0]), &len, &returnColumnSizes);

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
    tcase_add_test(t, test_official);
}