/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/28 下午12:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0049.c"

START_TEST(test_official) {
    int len = 0, *returnColumnSizes = NULL, col[] = { 3, 2, 1 };
    char *arr[]       = { "eat", "tea", "tan", "ate", "nat", "bat" };
    char *target[][3] = { { "ate", "tea", "eat" }, { "nat", "tan" }, { "bat" } };

    char ***ans = groupAnagrams(arr, LEN(arr), &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col[i]);
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
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