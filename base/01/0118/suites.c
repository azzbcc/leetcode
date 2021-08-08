/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/6 下午1:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0118.c"

START_TEST(test_official) {
    int n = 5, len = 0, *returnColumnSizes = NULL;
    int target[][5] = { { 1 }, { 1, 1 }, { 1, 2, 1 }, { 1, 3, 3, 1 }, { 1, 4, 6, 4, 1 } };
    int **ans       = generate(n, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], i + 1);
        ck_assert_mem_eq(ans[i], target[i], returnColumnSizes[i] * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}