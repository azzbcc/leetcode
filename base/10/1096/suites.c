/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/7 上午9:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1096.c"

START_TEST(test_official_1) {
    int len;
    char *expression = "{a,b}{c,{d,e}}";
    char *target[]   = { "ac", "ad", "ae", "bc", "bd", "be" };
    char **ans       = braceExpansionII(expression, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char *expression = "{{a,z},a{b,c},{ab,z}}";
    char *target[]   = { "a", "ab", "ac", "z" };
    char **ans       = braceExpansionII(expression, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_failed) {
    int len;
    char *expression = "{a,b}c{d,e}f";
    char *target[]   = { "acdf", "acef", "bcdf", "bcef" };
    char **ans       = braceExpansionII(expression, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}