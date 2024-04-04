/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/4 11:41
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2192.c"

START_TEST(test_official_1) {
    int len = 0, *returnColumnSizes = NULL;
    int n = 8, col[] = { 0, 0, 0, 2, 2, 3, 5, 4 };
    int *edgeList[] = { (int[]) { 0, 3 }, (int[]) { 0, 4 }, (int[]) { 1, 3 }, (int[]) { 2, 4 }, (int[]) { 2, 7 },
                        (int[]) { 3, 5 }, (int[]) { 3, 6 }, (int[]) { 3, 7 }, (int[]) { 4, 6 } };
    int *target[]   = { (int[]) {},
                        (int[]) {},
                        (int[]) {},
                        (int[]) { 0, 1 },
                        (int[]) { 0, 2 },
                        (int[]) { 0, 1, 3 },
                        (int[]) { 0, 1, 2, 3, 4 },
                        (int[]) { 0, 1, 2, 3 } };
    int **ans       = getAncestors(n, edgeList, LEN(edgeList), NULL, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(col[i], returnColumnSizes[i]);
        ck_assert_mem_eq(ans[i], target[i], col[i] * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

START_TEST(test_official_2) {
    int len = 0, *returnColumnSizes = NULL;
    int n = 5, col[] = { 0, 1, 2, 3, 4 };
    int *edgeList[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 }, (int[]) { 0, 3 }, (int[]) { 0, 4 }, (int[]) { 1, 2 },
                        (int[]) { 1, 3 }, (int[]) { 1, 4 }, (int[]) { 2, 3 }, (int[]) { 2, 4 }, (int[]) { 3, 4 } };
    int *target[]   = { (int[]) {}, (int[]) { 0 }, (int[]) { 0, 1 }, (int[]) { 0, 1, 2 }, (int[]) { 0, 1, 2, 3 } };
    int **ans       = getAncestors(n, edgeList, LEN(edgeList), NULL, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(col[i], returnColumnSizes[i]);
        ck_assert_mem_eq(ans[i], target[i], col[i] * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}