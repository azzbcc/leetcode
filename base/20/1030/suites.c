/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/17 上午11:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1030.c"

START_TEST(test_official_1) {
    int R = 1, C = 2, r0 = 0, c0 = 0;
    int len = 0, *returnColumnSizes = NULL;
    int target[][2] = { { 0, 0 }, { 0, 1 } };

    int **ans = allCellsDistOrder(R, C, r0, c0, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], LEN(target[i]));
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int R = 2, C = 2, r0 = 0, c0 = 1;
    int len = 0, *returnColumnSizes = NULL;
    int target[][2] = { { 0, 1 }, { 0, 0 }, { 1, 1 }, { 1, 0 } };

    int **ans = allCellsDistOrder(R, C, r0, c0, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], LEN(target[i]));
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_3) {
    int R = 2, C = 3, r0 = 1, c0 = 2;
    int len = 0, *returnColumnSizes = NULL;
    int target[][2] = { { 1, 2 }, { 0, 2 }, { 1, 1 }, { 0, 1 }, { 1, 0 }, { 0, 0 } };

    int **ans = allCellsDistOrder(R, C, r0, c0, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], LEN(target[i]));
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_failed) {
    int R = 3, C = 5, r0 = 2, c0 = 3;
    int len = 0, *returnColumnSizes = NULL;
    int target[][2] = { { 2, 3 }, { 1, 3 }, { 2, 2 }, { 2, 4 }, { 0, 3 }, { 1, 2 }, { 1, 4 }, { 2, 1 },
                        { 0, 2 }, { 0, 4 }, { 1, 1 }, { 2, 0 }, { 0, 1 }, { 1, 0 }, { 0, 0 } };

    int **ans = allCellsDistOrder(R, C, r0, c0, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], LEN(target[i]));
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}