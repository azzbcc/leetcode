/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/7/4 上午9:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1200.c"

START_TEST(test_official_1) {
    int arr[] = { 4, 2, 1, 3 };
    int len, *returnColumnSizes = NULL;
    int *target[] = { (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 3, 4 } };

    int **ans = minimumAbsDifference(arr, LEN(arr), &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], returnColumnSizes[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 3, 6, 10, 15 };
    int len, *returnColumnSizes = NULL;
    int *target[] = { (int[]) { 1, 3 } };

    int **ans = minimumAbsDifference(arr, LEN(arr), &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], returnColumnSizes[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_3) {
    int arr[] = { 3, 8, -10, 23, 19, -4, -14, 27 };
    int len, *returnColumnSizes = NULL;
    int *target[] = { (int[]) { -14, -10 }, (int[]) { 19, 23 }, (int[]) { 23, 27 } };

    int **ans = minimumAbsDifference(arr, LEN(arr), &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], returnColumnSizes[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}