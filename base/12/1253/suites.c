/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/29 20:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1253.c"

void check(bool flag, int **ans, int upper, int lower, int *colsum, int size, int len, int *returnColumnSizes) {
    int sum[2] = { 0 };

    if (!flag) {
        ck_assert_int_eq(len, 0);
        return;
    }
    ck_assert_int_eq(len, 2);
    for (int i = 0; i < 2; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], size);
    }
    for (int i = 0; i < size; ++i) {
        ck_assert_int_ge(ans[0][i], 0);
        ck_assert_int_ge(ans[1][i], 0);
        ck_assert_int_lt(ans[0][i], 2);
        ck_assert_int_lt(ans[1][i], 2);
        ck_assert_int_eq(colsum[i], ans[0][i] + ans[1][i]);
        sum[0] += ans[0][i], sum[1] += ans[1][i];
    }
    ck_assert_int_eq(sum[0], upper);
    ck_assert_int_eq(sum[1], lower);
}

START_TEST(test_official_1) {
    int len = 0, *returnColumnSizes = NULL;
    int upper = 2, lower = 1, colsum[] = { 1, 1, 1 };
    int **ans = reconstructMatrix(upper, lower, colsum, LEN(colsum), &len, &returnColumnSizes);

    check(true, ans, upper, lower, colsum, LEN(colsum), len, returnColumnSizes);
    free(ans[0]);
    free(ans[1]);
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int len = 0, *returnColumnSizes = NULL;
    int upper = 2, lower = 3, colsum[] = { 2, 2, 1, 1 };
    int **ans = reconstructMatrix(upper, lower, colsum, LEN(colsum), &len, &returnColumnSizes);

    check(false, ans, upper, lower, colsum, LEN(colsum), len, returnColumnSizes);
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_3) {
    int len = 0, *returnColumnSizes = NULL;
    int upper = 5, lower = 5, colsum[] = { 2, 1, 2, 0, 1, 0, 1, 2, 0, 1 };
    int **ans = reconstructMatrix(upper, lower, colsum, LEN(colsum), &len, &returnColumnSizes);

    check(true, ans, upper, lower, colsum, LEN(colsum), len, returnColumnSizes);
    free(ans[0]);
    free(ans[1]);
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}