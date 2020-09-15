/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/15 下午12:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0917.c"

START_TEST(test_official_1) {
    char input[] = { "ab-cd" };
    char *target = "dc-ba", *ans = reverseOnlyLetters(input);
    ck_assert_str_eq(target, ans);
}

START_TEST(test_official_2) {
    char input[] = { "a-bC-dEf-ghIj" };
    char *target = "j-Ih-gfE-dCba", *ans = reverseOnlyLetters(input);
    ck_assert_str_eq(target, ans);
}

START_TEST(test_official_3) {
    char input[] = { "Test1ng-Leet=code-Q!" };
    char *target = "Qedo1ct-eeLg=ntse-T!", *ans = reverseOnlyLetters(input);
    ck_assert_str_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}