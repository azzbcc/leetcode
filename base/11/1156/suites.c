/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/6/3 11:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1156.c"

START_TEST(test_official_1) {
    char *text = "ababa";
    int target = 3, ans = maxRepOpt1(text);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *text = "aaabaaa";
    int target = 6, ans = maxRepOpt1(text);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *text = "aaabbaaa";
    int target = 4, ans = maxRepOpt1(text);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *text = "aaaaa";
    int target = 5, ans = maxRepOpt1(text);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    char *text = "abcdef";
    int target = 1, ans = maxRepOpt1(text);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}