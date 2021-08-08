/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/20 下午7:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0316.c"

START_TEST(test_official_1) {
    char *s      = "bcabc";
    char *target = "abc", *ans = removeDuplicateLetters(s);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s      = "cbacdcbc";
    char *target = "acdb", *ans = removeDuplicateLetters(s);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed) {
    char *s      = "abacb";
    char *target = "abc", *ans = removeDuplicateLetters(s);

    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}