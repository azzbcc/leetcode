/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/7 下午6:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0020.c"

START_TEST(test_official_1) {
    char *input = "()";
    bool target = true, ans = isValid(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on isValid(%s).", target, ans, input);
}

START_TEST(test_official_2) {
    char *input = "()[]{}";
    bool target = true, ans = isValid(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on isValid(%s).", target, ans, input);
}

START_TEST(test_official_3) {
    char *input = "(]";
    bool target = false, ans = isValid(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on isValid(%s).", target, ans, input);
}

START_TEST(test_official_4) {
    char *input = "([)]";
    bool target = false, ans = isValid(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on isValid(%s).", target, ans, input);
}

START_TEST(test_official_5) {
    char *input = "{[]}";
    bool target = true, ans = isValid(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on isValid(%s).", target, ans, input);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}