/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/5/22 10:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2225.c"

START_TEST(test_official_1) {
    int len = 0, *returnColumnSizes = NULL;
    int *matches[] = { (int[]) { 1, 3 }, (int[]) { 2, 3 }, (int[]) { 3, 6 }, (int[]) { 5, 6 },  (int[]) { 5, 7 },
                       (int[]) { 4, 5 }, (int[]) { 4, 8 }, (int[]) { 4, 9 }, (int[]) { 10, 4 }, (int[]) { 10, 9 } };
    int *target[] = { (int[]) { 1, 2, 10 }, (int[]) { 4, 5, 7, 8 } }, col[] = { 3, 4 };
    int **ans = findWinners(matches, LEN(matches), NULL, &len, &returnColumnSizes);
    ck_assert_int_eq(LEN(target), len);
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(col[i], returnColumnSizes[i]);
        ck_assert_mem_eq(ans[i], target[i], col[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int len = 0, *returnColumnSizes = NULL;
    int *matches[] = { (int[]) { 2, 3 }, (int[]) { 1, 3 }, (int[]) { 5, 4 }, (int[]) { 6, 4 } };
    int *target[] = { (int[]) { 1, 2, 5, 6 }, (int[]) {} }, col[] = { 4, 0 };
    int **ans = findWinners(matches, LEN(matches), NULL, &len, &returnColumnSizes);
    ck_assert_int_eq(LEN(target), len);
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