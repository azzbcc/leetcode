/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/16 上午11:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0406.c"

START_TEST(test_official) {
    int arr[][2] = { { 7, 0 }, { 4, 4 }, { 7, 1 }, { 5, 0 }, { 6, 1 }, { 5, 2 } };
    int *grid[]  = { arr[0], arr[1], arr[2], arr[3], arr[4], arr[5] };

    int len = 0, *returnColumnSizes = NULL;
    int target[][2] = { { 5, 0 }, { 7, 0 }, { 5, 2 }, { 6, 1 }, { 4, 4 }, { 7, 1 } };

    int **ans = reconstructQueue(grid, LEN(grid), NULL, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], LEN(target[i]));
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_failed) {
    int arr[][2] = {
        { 9, 0 }, { 7, 0 }, { 1, 9 }, { 3, 0 }, { 2, 7 }, { 5, 3 }, { 6, 0 }, { 3, 4 }, { 6, 2 }, { 5, 2 }
    };
    int *grid[] = { arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9] };

    int len = 0, *returnColumnSizes = NULL;
    int target[][2] = { { 3, 0 }, { 6, 0 }, { 7, 0 }, { 5, 2 }, { 3, 4 },
                        { 5, 3 }, { 6, 2 }, { 2, 7 }, { 9, 0 }, { 1, 9 } };

    int **ans = reconstructQueue(grid, LEN(grid), NULL, &len, &returnColumnSizes);

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
    tcase_add_test(t, test_official);
}