/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/7 下午5:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0017.c"

int comp(const void *a, const void *b) {
    return strcmp(*( char ** )a, *( char ** )b);
}

START_TEST(test_official) {
    int len;
    char *arr = "23", *target[] = { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };
    char **ans = letterCombinations(arr, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));

    qsort(ans, len, sizeof(ans[0]), comp);
    qsort(target, len, sizeof(target[0]), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_failed) {
    int len;
    char *arr = "";

    letterCombinations(arr, &len);

    ck_assert_int_eq(len, 0);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}