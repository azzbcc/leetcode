/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/24 下午4:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0139.c"

START_TEST(test_official_1) {
    char *s = "leetcode", *words[] = { "leet", "code" };

    bool target = true, ans = wordBreak(s, words, sizeof(words) / sizeof(words[0]));

    ck_assert_int_eq(target, ans);
}
START_TEST(test_official_2) {
    char *s = "applepenapple", *words[] = { "apple", "pen" };

    bool target = true, ans = wordBreak(s, words, sizeof(words) / sizeof(words[0]));

    ck_assert_int_eq(target, ans);
}
START_TEST(test_official_3) {
    char *s = "catsandog", *words[] = { "cats", "dog", "sand", "and", "cat" };

    bool target = false, ans = wordBreak(s, words, sizeof(words) / sizeof(words[0]));

    ck_assert_int_eq(target, ans);
}
START_TEST(test_tle) {
    char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
              "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
         *words[] = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };

    bool target = false, ans = wordBreak(s, words, sizeof(words) / sizeof(words[0]));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}