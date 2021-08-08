/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/5 下午2:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0127.c"

START_TEST(test_official_1) {
    char *beginWord = "hit", *endWord = "cog";
    char *wordList[] = { "hot", "dot", "dog", "lot", "log", "cog" };

    int target = 5, ans = ladderLength(beginWord, endWord, wordList, LEN(wordList));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    char *beginWord = "hit", *endWord = "cog";
    char *wordList[] = { "hot", "dot", "dog", "lot", "log" };

    int target = 0, ans = ladderLength(beginWord, endWord, wordList, LEN(wordList));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}