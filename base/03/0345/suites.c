/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/19 下午1:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0345.c"

START_TEST(test_official_1) {
    char str[]   = "hello";
    char *target = "holle", *ans = reverseVowels(str);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char str[]   = "leetcode";
    char *target = "leotcede", *ans = reverseVowels(str);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}