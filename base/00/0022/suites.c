/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/7/30 下午2:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */

#include <common.h>

#include "0022.c"

int cmp(const void *a, const void *b) {
    char *pa = *( char ** )a, *pb = *( char ** )b;
    return strcmp(pa, pb);
}

START_TEST(test_official) {
    int n = 3, size, target = 5;
    char *results[] = { "((()))", "(()())", "(())()", "()(())", "()()()" };

    char **ans = generateParenthesis(n, &size);

    ck_assert(target == size);
    qsort(ans, target, sizeof(ans[0]), cmp);

    for (int i = 0; i < target; ++i) {
        ck_assert_str_eq(ans[i], results[i]);
        free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}