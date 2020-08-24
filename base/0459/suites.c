/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/24 上午11:00
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0459.c"

START_TEST(test_official_1) {
    bool target = true, ans = repeatedSubstringPattern("abab");

    fail_if(target != ans);
}

START_TEST(test_official_2) {
    bool target = false, ans = repeatedSubstringPattern("aba");

    fail_if(target != ans);
}

START_TEST(test_official_3) {
    bool target = true, ans = repeatedSubstringPattern("abcabcabcabc");

    fail_if(target != ans);
}

START_TEST(test_failed_1) {
    bool target = true, ans = repeatedSubstringPattern("abacababacab");

    fail_if(target != ans);
}

START_TEST(test_failed_2) {
    bool target = true, ans = repeatedSubstringPattern("babbabbabbabbab");

    fail_if(target != ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}