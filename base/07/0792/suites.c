/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/17 下午2:01
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0792.c"

START_TEST(test_official_1) {
    char *s = "abcde", *words[] = { "a", "bb", "acd", "ace" };
    int target = 3, ans = numMatchingSubseq(s, words, LEN(words));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s = "dsahjpjauf", *words[] = { "ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax" };
    int target = 2, ans = numMatchingSubseq(s, words, LEN(words));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}