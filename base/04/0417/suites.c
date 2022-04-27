/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/27 上午11:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0417.c"

START_TEST(test_official_1) {
    int col = 5, len = 0, *returnColumnSizes = NULL;
    int *heights[] = { (int[]) { 1, 2, 2, 3, 5 }, (int[]) { 3, 2, 3, 4, 4 }, (int[]) { 2, 4, 5, 3, 1 },
                       (int[]) { 6, 7, 1, 4, 5 }, (int[]) { 5, 1, 1, 2, 4 } };
    int *target[]  = { (int[]) { 0, 4 }, (int[]) { 1, 3 }, (int[]) { 1, 4 }, (int[]) { 2, 2 },
                       (int[]) { 3, 0 }, (int[]) { 3, 1 }, (int[]) { 4, 0 } };
    int **ans      = pacificAtlantic(heights, LEN(heights), &col, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

START_TEST(test_official_2) {
    int col = 2, len = 0, *returnColumnSizes = NULL;
    int *heights[] = { (int[]) { 2, 1 }, (int[]) { 1, 2 } };
    int *target[]  = { (int[]) { 0, 0 }, (int[]) { 0, 1 }, (int[]) { 1, 0 }, (int[]) { 1, 1 } };
    int **ans      = pacificAtlantic(heights, LEN(heights), &col, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}