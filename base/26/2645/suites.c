/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/11 11:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2645.c"

START_TEST(test_official_1) {
    char *word = "b";
    int target = 2, ans = addMinimum(word);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *word = "aaa";
    int target = 6, ans = addMinimum(word);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *word = "abc";
    int target = 0, ans = addMinimum(word);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}