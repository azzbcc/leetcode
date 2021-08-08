/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/9 上午11:55
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0973.c"

START_TEST(test_official_1) {
    int arr[][2] = { { 1, 3 }, { -2, 2 } }, K = 1;
    int *grid[]     = { arr[0], arr[1] };
    int target[][2] = { { -2, 2 } };
    int len, *returnColumnSizes = NULL;
    int **ans = kClosest(grid, LEN(grid), NULL, K, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], LEN(target[i]));
        ck_assert_mem_eq(target[i], ans[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int arr[][2] = { { 3, 3 }, { 5, -1 }, { -2, 4 } }, K = 2;
    int *grid[]     = { arr[0], arr[1], arr[2] };
    int target[][2] = { { -2, 4 }, { 3, 3 } };
    int len, *returnColumnSizes = NULL;
    int **ans = kClosest(grid, LEN(grid), NULL, K, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], LEN(target[i]));
        ck_assert_mem_eq(target[i], ans[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}
START_TEST(test_failed) {
    int arr[][2] = { { -63, -55 }, { -20, 17 }, { -88, -82 }, { -90, -95 }, { -88, 18 },  { -62, -21 }, { 71, -64 },
                     { -14, 56 },  { 65, 90 },  { -48, -52 }, { 59, 92 },   { -44, -59 }, { -3, -66 } };
    int K = 7, *grid[] = { arr[0], arr[1], arr[2], arr[3],  arr[4],  arr[5], arr[6],
                           arr[7], arr[8], arr[9], arr[10], arr[11], arr[12] };
    int target[][2] = { { -63, -55 }, { -44, -59 }, { -48, -52 }, { -20, 17 }, { -3, -66 }, { -62, -21 }, { -14, 56 } };
    int len, *returnColumnSizes = NULL;
    int **ans = kClosest(grid, LEN(grid), NULL, K, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], LEN(target[i]));
        ck_assert_mem_eq(target[i], ans[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}