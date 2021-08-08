/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/8 上午11:01
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0077.c"

int array_comp(const void *a, const void *b) {
    int *pa = ( int * )a, *pb = ( int * )b;

    if (pa[0] == pb[0]) { return pa[1] - pb[1]; }
    return pa[0] - pb[0];
}
int point_comp(const void *a, const void *b) {
    int **pa = ( int ** )a, **pb = ( int ** )b;

    if (pa[0][0] == pb[0][0])  return pa[0][1] - pb[0][1];
    return pa[0][0] - pb[0][0];
}
START_TEST(test_official) {
    int len = 0, *returnColumnSizes = NULL;
    int target[][2] = { { 2, 4 }, { 3, 4 }, { 2, 3 }, { 1, 2 }, { 1, 3 }, { 1, 4 } };

    int **ans = combine(4, 2, &len, &returnColumnSizes);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));

    qsort(ans, len, sizeof(int *), point_comp);
    qsort(target, len, sizeof(target[0]), array_comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_mem_eq(ans[i], target[i], sizeof(target[i]));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}