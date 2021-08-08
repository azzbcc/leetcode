/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/13 下午1:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0218.c"

START_TEST(test_official_1) {
    int *buildings[] = { (int[]) { 2, 9, 10 }, (int[]) { 3, 7, 15 }, (int[]) { 5, 12, 12 }, (int[]) { 15, 20, 10 },
                         (int[]) { 19, 24, 8 } };
    int *target[]    = { (int[]) { 2, 10 },  (int[]) { 3, 15 }, (int[]) { 7, 12 }, (int[]) { 12, 0 },
                      (int[]) { 15, 10 }, (int[]) { 20, 8 }, (int[]) { 24, 0 } };
    int len = 0, *returnColumnSizes = NULL;
    int **ans = getSkyline(buildings, LEN(buildings), NULL, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int *buildings[] = { (int[]) { 0, 2, 3 }, (int[]) { 2, 5, 3 } };
    int *target[]    = { (int[]) { 0, 3 }, (int[]) { 5, 0 } };
    int len = 0, *returnColumnSizes = NULL;
    int **ans = getSkyline(buildings, LEN(buildings), NULL, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_own) {
    int *buildings[] = { (int[]) { 0, 2, 3 }, (int[]) { 1, 2, 4 } };
    int *target[]    = { (int[]) { 0, 3 }, (int[]) { 1, 4 }, (int[]) { 2, 0 } };
    int len = 0, *returnColumnSizes = NULL;
    int **ans = getSkyline(buildings, LEN(buildings), NULL, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}