/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/2 下午12:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0424.c"

START_TEST(test_official_1) {
    char *s = "ABAB";
    int target = 4, ans = characterReplacement(s, 2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s = "AABABBA";
    int target = 4, ans = characterReplacement(s, 1);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    char *s = "AABA";
    int target = 2, ans = characterReplacement(s, 0);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}