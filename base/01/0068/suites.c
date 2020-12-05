/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/5 下午5:11
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0068.c"

START_TEST(test_official_1) {
    int len, maxWidth = 16;
    char *words[]  = { "This", "is", "an", "example", "of", "text", "justification." };
    char *target[] = { "This    is    an", "example  of text", "justification.  " };

    char **ans = fullJustify(words, LEN(words), maxWidth, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len, maxWidth = 16;
    char *words[]  = { "What", "must", "be", "acknowledgment", "shall", "be" };
    char *target[] = { "What   must   be", "acknowledgment  ", "shall be        " };

    char **ans = fullJustify(words, LEN(words), maxWidth, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_3) {
    int len, maxWidth = 20;
    char *words[]  = { "Science", "is", "what",      "we",  "understand", "well",       "enough", "to", "explain",
                      "to",      "a",  "computer.", "Art", "is",         "everything", "else",   "we", "do" };
    char *target[] = { "Science  is  what we", "understand      well", "enough to explain to",
                       "a  computer.  Art is", "everything  else  we", "do                  " };

    char **ans = fullJustify(words, LEN(words), maxWidth, &len);
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
    tcase_add_test(t, test_official_3);
}