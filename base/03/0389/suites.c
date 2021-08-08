/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/18 上午11:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0389.c"

START_TEST(test_official_1) {
    char *s = "abcd", *t = "abcde";
    char target = 'e', ans = findTheDifference(s, t);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s = "", *t = "y";
    char target = 'y', ans = findTheDifference(s, t);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s = "a", *t = "aa";
    char target = 'a', ans = findTheDifference(s, t);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *s = "ae", *t = "aea";
    char target = 'a', ans = findTheDifference(s, t);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}