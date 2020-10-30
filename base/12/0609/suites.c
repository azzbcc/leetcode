/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/30 下午1:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0609.c"

START_TEST(test_official) {
    int len, *returnColumnSizes = NULL, col[] = { 2, 3 };
    char d1[] = "root/a 1.txt(abcd) 2.txt(efgh)", d2[] = "root/c 3.txt(abcd)";
    char d3[] = "root/c/d 4.txt(efgh)", d4[] = "root 4.txt(efgh)";
    char *grid[] = { d1, d2, d3, d4 };

    char *target[][3] = { { "root/c/3.txt", "root/a/1.txt" }, { "root/4.txt", "root/c/d/4.txt", "root/a/2.txt" } };
    char ***ans       = findDuplicate(grid, LEN(grid), &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(col[i], returnColumnSizes[i]);
        for (int j = 0; j < col[i]; ++j) {
            ck_assert_str_eq(target[i][j], ans[i][j]);
            free(ans[i][j]);
        }
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_failed) {
    int len, *returnColumnSizes = NULL, col[] = {};
    char d1[] = "root/a 1.txt(abcd) 2.txt(efsfgh)", d2[] = "root/c 3.txt(abdfcd)", d3[] = "root/c/d 4.txt(efggdfh)";
    char *grid[] = { d1, d2, d3 };

    char *target[][1] = {};
    char ***ans       = findDuplicate(grid, LEN(grid), &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(col[i], returnColumnSizes[i]);
        for (int j = 0; j < col[i]; ++j) {
            ck_assert_str_eq(target[i][j], ans[i][j]);
            free(ans[i][j]);
        }
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}