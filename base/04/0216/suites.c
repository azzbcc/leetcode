/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/11 下午2:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0040.c"

START_TEST(test_official_1) {
    int k = 3, n = 7;
    int target[][3] = { { 1, 2, 4 } };
    int len = 0, *returnColumnSizes = NULL;
    int **ans = combinationSum3(k, n, &len, &returnColumnSizes);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], k);
        ck_assert_mem_eq(ans[i], target[i], k * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int k = 3, n = 9;
    int target[][3] = { { 1, 2, 6 }, { 1, 3, 5 }, { 2, 3, 4 } };
    int len = 0, *returnColumnSizes = NULL;
    int **ans = combinationSum3(k, n, &len, &returnColumnSizes);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], k);
        ck_assert_mem_eq(ans[i], target[i], k * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}