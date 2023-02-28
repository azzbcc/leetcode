/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/28 下午3:11
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2363.c"

START_TEST(test_official_1) {
    int len, *returnColumnSizes = NULL;
    int *items1[] = { (int[]) { 1, 1 }, (int[]) { 4, 5 }, (int[]) { 3, 8 } };
    int *items2[] = { (int[]) { 3, 1 }, (int[]) { 1, 5 } };
    int *target[] = { (int[]) { 1, 6 }, (int[]) { 3, 9 }, (int[]) { 4, 5 } };
    int **ans     = mergeSimilarItems(items1, LEN(items1), NULL, items2, LEN(items2), NULL, &len, &returnColumnSizes);
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
    int len, *returnColumnSizes = NULL;
    int *items1[] = { (int[]) { 1, 1 }, (int[]) { 3, 2 }, (int[]) { 2, 3 } };
    int *items2[] = { (int[]) { 2, 1 }, (int[]) { 3, 2 }, (int[]) { 1, 3 } };
    int *target[] = { (int[]) { 1, 4 }, (int[]) { 2, 4 }, (int[]) { 3, 4 } };
    int **ans     = mergeSimilarItems(items1, LEN(items1), NULL, items2, LEN(items2), NULL, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_3) {
    int len, *returnColumnSizes = NULL;
    int *items1[] = { (int[]) { 1, 3 }, (int[]) { 2, 2 } };
    int *items2[] = { (int[]) { 7, 1 }, (int[]) { 2, 2 }, (int[]) { 1, 4 } };
    int *target[] = { (int[]) { 1, 7 }, (int[]) { 2, 4 }, (int[]) { 7, 1 } };
    int **ans     = mergeSimilarItems(items1, LEN(items1), NULL, items2, LEN(items2), NULL, &len, &returnColumnSizes);
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
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}