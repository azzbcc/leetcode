/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/24 下午3:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0661.c"

START_TEST(test_official_1) {
    int len = 0, *returnColumnSizes = NULL;
    int col = 3, *img[] = { (int[]) { 1, 1, 1 }, (int[]) { 1, 0, 1 }, (int[]) { 1, 1, 1 } };
    int target[][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };

    int **ans = imageSmoother(img, LEN(img), &col, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(LEN(target[i]), returnColumnSizes[i]);
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int len = 0, *returnColumnSizes = NULL;
    int col = 3, *img[] = { (int[]) { 100, 200, 100 }, (int[]) { 200, 50, 200 }, (int[]) { 100, 200, 100 } };
    int target[][3] = { { 137, 141, 137 }, { 141, 138, 141 }, { 137, 141, 137 } };

    int **ans = imageSmoother(img, LEN(img), &col, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(LEN(target[i]), returnColumnSizes[i]);
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}