/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/3 上午11:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0051.c"

START_TEST(test_official) {
    int N   = 4;
    int len = 0, *returnColumnSizes = NULL;
    char *target[][4] = { { ".Q..", "...Q", "Q...", "..Q." }, { "..Q.", "Q...", "...Q", ".Q.." } };
    char ***ans       = solveNQueens(N, &len, &returnColumnSizes);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], sizeof(target[i]) / sizeof(target[i][0]));
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            ck_assert_str_eq(ans[i][j], target[i][j]);
            free(ans[i][j]);
        }
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}