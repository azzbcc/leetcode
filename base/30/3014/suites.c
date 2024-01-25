/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/25 15:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "3014.c"

START_TEST(test_official_1) {
    char *word = "abcde";
    int target = 5, ans = minimumPushes(word);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *word = "xycdefghij";
    int target = 12, ans = minimumPushes(word);
    ck_assert_int_eq(ans, target);}

START_TEST(test_failed) {
    char *word = "acolkxjbizfmhnrdq";
    int target = 27, ans = minimumPushes(word);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}