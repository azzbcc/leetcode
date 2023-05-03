/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/5/3 12:27
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1003.c"

START_TEST(test_official_1) {
    char *s = "aabcbc";
    ck_assert_int_eq(true, isValid(s));
}

START_TEST(test_official_2) {
    char *s = "abcabcababcc";
    ck_assert_int_eq(true, isValid(s));
}

START_TEST(test_official_3) {
    char *s = "abccba";
    ck_assert_int_eq(false, isValid(s));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}