/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/27 下午9:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1048.c"

START_TEST(test_official_1) {
    char *words[] = { "a", "b", "ba", "bca", "bda", "bdca" };
    int target = 4, ans = longestStrChain(words, LEN(words));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *words[] = { "xbc", "pcxbcf", "xb", "cxbc", "pcxbc" };
    int target = 5, ans = longestStrChain(words, LEN(words));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *words[] = { "abcd", "dbqca" };
    int target = 1, ans = longestStrChain(words, LEN(words));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    char *words[] = { "a", "b", "bca", "bda", "bdca" };
    int target = 2, ans = longestStrChain(words, LEN(words));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}