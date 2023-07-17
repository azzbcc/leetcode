/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/7 下午6:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0018.c"

int compare(int *pa, int *pb) {
    if (pa[0] == pb[0]) {
        if (pa[1] == pb[1]) {
            if (pa[2] == pb[2]) return pa[3] - pb[3];
            return pa[2] - pb[2];
        }
        return pa[1] - pb[1];
    }
    return pa[0] - pb[0];
}
int array_comp(const void *a, const void *b) {
    int *pa = ( int * )a, *pb = ( int * )b;

    return compare(pa, pb);
}
int ptr_comp(const void *a, const void *b) {
    int **pa = ( int ** )a, **pb = ( int ** )b;

    return compare(*pa, *pb);
}

START_TEST(test_official) {
    int input = 0, arr[] = { 1, 0, -1, 0, -2, 2 };
    int target[][4] = { { -1, 0, 0, 1 }, { -2, -1, 1, 2 }, { -2, 0, 0, 2 } };
    int len = 0, *returnColumnSizes = NULL;

    int **ans = fourSum(arr, sizeof(arr) / sizeof(arr[0]), input, &len, &returnColumnSizes);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));

    qsort(target, len, sizeof(target[0]), array_comp);
    qsort(ans, len, sizeof(int *), ptr_comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_failed_1) {
    int input = 0, arr[] = { 1000000000, 1000000000, 1000000000, 1000000000 };
    int target[][4] = {};
    int len = 0, *returnColumnSizes = NULL;

    int **ans = fourSum(arr, sizeof(arr) / sizeof(arr[0]), input, &len, &returnColumnSizes);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));

    qsort(target, len, sizeof(target[0]), array_comp);
    qsort(ans, len, sizeof(int *), ptr_comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_failed_2) {
    int input = -1, arr[] = { -1, 0, 1, 2, -1, -4 };
    int target[][4] = { { -4, 0, 1, 2 }, { -1, -1, 0, 1 } };
    int len = 0, *returnColumnSizes = NULL;

    int **ans = fourSum(arr, sizeof(arr) / sizeof(arr[0]), input, &len, &returnColumnSizes);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));

    qsort(target, len, sizeof(target[0]), array_comp);
    qsort(ans, len, sizeof(int *), ptr_comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official);
}