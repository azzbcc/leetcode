/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/18 上午12:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0721.c"

START_TEST(test_official) {
    int len, *returnColumnSizes;
    int grid_col[] = { 3, 2, 3, 2 }, target_col[] = { 4, 2, 2 };
    char *accounts[][3] = { { "John", "johnsmith@mail.com", "john00@mail.com" },
                            { "John", "johnnybravo@mail.com" },
                            { "John", "johnsmith@mail.com", "john_newyork@mail.com" },
                            { "Mary", "mary@mail.com" } };
    char **grid[]       = { accounts[0], accounts[1], accounts[2], accounts[3] };
    char *target[][4]   = { { "John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com" },
                          { "John", "johnnybravo@mail.com" },
                          { "Mary", "mary@mail.com" } };

    char ***ans = accountsMerge(grid, LEN(grid), grid_col, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], target_col[i]);
        for (int j = 0; j < target_col[i]; ++j) {
            ck_assert_str_eq(ans[i][j], target[i][j]);
        }
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}