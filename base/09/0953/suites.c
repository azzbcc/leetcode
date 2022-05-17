/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/17 上午11:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0953.c"

START_TEST(test_official_1) {
    char *words[] = { "hello", "leetcode" }, *order = "hlabcdefgijkmnopqrstuvwxyz";
    bool target = true, ans = isAlienSorted(words, LEN(words), order);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *words[] = { "word", "world", "row" }, *order = "worldabcefghijkmnpqstuvxyz";
    bool target = false, ans = isAlienSorted(words, LEN(words), order);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *words[] = { "apple", "app" }, *order = "abcdefghijklmnopqrstuvwxyz";
    bool target = false, ans = isAlienSorted(words, LEN(words), order);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    char *words[] = { "app", "apple" }, *order = "abcdefghijklmnopqrstuvwxyz";
    bool target = true, ans = isAlienSorted(words, LEN(words), order);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}