/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/7/30 下午2:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */

#include <check.h>
#include <assert.h>
#include <stdlib.h>

#include "0022.c"

int compare(const char **a, const char **b) {
    return strcmp(*a, *b);
}

START_TEST(test_official) {
    int n = 3, size, target = 5;
    char *results[] = { "((()))", "(()())", "(())()", "()(())", "()()()" };

    char **ans = generateParenthesis(n, &size);

    ck_assert(target == size);
    qsort(ans, target, sizeof(ans[0]), ( __compar_fn_t )compare);

    for (int i = 0; i < target; ++i) {
        ck_assert_msg(!strcmp(results[i], ans[i]), "error, except %s but got %s on generateParenthesis(%d).", results[i],
                      ans[i], n);
        free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}