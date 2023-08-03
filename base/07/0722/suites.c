/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/8/3 14:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0722.c"

START_TEST(test_official_1) {
    int len;
    char *source[] = { "/*Test program */",
                       "int main()",
                       "{ ",
                       "  // variable declaration ",
                       "int a, b, c;",
                       "/* This is a test",
                       "   multiline  ",
                       "   comment for ",
                       "   testing */",
                       "a = b + c;",
                       "}" };
    char *target[] = { "int main()", "{ ", "  ", "int a, b, c;", "a = b + c;", "}" };
    char **ans     = removeComments(source, LEN(source), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char *source[] = { "a/*comment", "line", "more_comment*/b" };
    char *target[] = { "ab" };
    char **ans     = removeComments(source, LEN(source), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}