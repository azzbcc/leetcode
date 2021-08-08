/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/25 下午1:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0491.c"

int array_comp(const void *a, const void *b) {
    int *pa = ( int * )a, *pb = ( int * )b;

    if (pa[0] == pb[0]) { return pa[1] - pb[1]; }
    return pa[0] - pb[0];
}
int point_comp(const void *a, const void *b) {
    int **pa = ( int ** )a, **pb = ( int ** )b;

    if (pa[0][0] == pb[0][0]) { return pa[0][1] - pb[0][1]; }
    return pa[0][0] - pb[0][0];
}

START_TEST(test_official) {
    int arr[]       = { 4, 6, 7, 7 };
    int target[][4] = { { 4, 6 }, { 4, 6, 7 }, { 4, 6, 7, 7 }, { 4, 7 }, { 4, 7, 7 }, { 6, 7 }, { 6, 7, 7 }, { 7, 7 } };
    int len = 0, *returnColumnSizes = NULL;

    int **ans = findSubsequences(arr, sizeof(arr) / sizeof(arr[0]), &len, &returnColumnSizes);

    fail_if(len != sizeof(target) / sizeof(target[0]));

    for (int i = 0; i < len; ++i) {
        ck_assert_mem_eq(ans[i], target[i], returnColumnSizes[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_failed) {
    int arr[]       = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 1, 1, 1, 1 };
    int len = 0, *returnColumnSizes = NULL;

    int **ans = findSubsequences(arr, sizeof(arr) / sizeof(arr[0]), &len, &returnColumnSizes);

    ck_assert_int_eq(len, 1018);

    for (int i = 0; i < len; ++i) {
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_repeat) {
    int arr[]       = { 1, 1, 2, 1, 1 };
    int target[][8] = { { 1, 1 }, { 1, 1, 2 }, { 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 2 } };
    int len = 0, *returnColumnSizes = NULL;

    int **ans = findSubsequences(arr, sizeof(arr) / sizeof(arr[0]), &len, &returnColumnSizes);

    fail_if(len != sizeof(target) / sizeof(target[0]));

    for (int i = 0; i < len; ++i) {
        ck_assert_mem_eq(ans[i], target[i], returnColumnSizes[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_repeat);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}