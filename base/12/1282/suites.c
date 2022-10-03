/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/12 上午11:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1282.c"

START_TEST(test_official_1) {
    int len = 0, *returnColumnSizes = NULL;
    int groupSizes[] = { 3, 3, 3, 3, 3, 1, 3 };
    int *target[] = { (int[]) { 5 }, (int[]) { 0, 1, 2 }, (int[]) { 3, 4, 6 } }, col[] = { 1, 3, 3 };
    int **ans = groupThePeople(groupSizes, LEN(groupSizes), &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col[i]);
        ck_assert_mem_eq(ans[i], target[i], col[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int len = 0, *returnColumnSizes = NULL;
    int groupSizes[] = { 2, 1, 3, 3, 3, 2 };
    int *target[] = { (int[]) { 1 }, (int[]) { 0, 5 }, (int[]) { 2, 3, 4 } }, col[] = { 1, 2, 3 };
    int **ans = groupThePeople(groupSizes, LEN(groupSizes), &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col[i]);
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