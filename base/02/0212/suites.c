/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/16 上午10:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0212.c"

START_TEST(test_official_1) {
    int len, col = 4;
    char *board[]  = { "oaan", "etae", "ihkr", "iflv" };
    char *words[]  = { "oath", "pea", "eat", "rain" };
    char *target[] = { "oath", "eat" };
    char **ans     = findWords(board, LEN(board), &col, words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len, col = 2;
    char *board[]  = { "ab", "cd" };
    char *words[]  = { "abcb" };
    char *target[] = {};
    char **ans     = findWords(board, LEN(board), &col, words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}