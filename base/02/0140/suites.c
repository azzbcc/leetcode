/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/1 上午11:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0140.c"

START_TEST(test_official_1) {
    int len;
    char *s = "catsanddog", *wordDict[] = { "cat", "cats", "and", "sand", "dog" };
    char *target[] = { "cats and dog", "cat sand dog" };

    char **ans = wordBreak(s, wordDict, LEN(wordDict), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char *s = "pineapplepenapple", *wordDict[] = { "apple", "pen", "applepen", "pine", "pineapple" };
    char *target[] = { "pine apple pen apple", "pineapple pen apple", "pine applepen apple" };

    char **ans = wordBreak(s, wordDict, LEN(wordDict), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_3) {
    int len;
    char *s = "catsandog", *wordDict[] = { "cats", "dog", "sand", "and", "cat" };
    char *target[] = {};

    char **ans = wordBreak(s, wordDict, LEN(wordDict), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_failed) {
    int len;
    char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
              "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char *wordDict[] = {
        "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"
    };
    char *target[] = {};

    char **ans = wordBreak(s, wordDict, LEN(wordDict), &len);

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
    tcase_add_test(t, test_official_3);
}