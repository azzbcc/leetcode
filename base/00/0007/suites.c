/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/3 下午5:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdlib.h>

#include "0007.c"

START_TEST(test_official_1) {
    int input = 123, target = 321, ans = reverse(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on reverse(%d).", target, ans, input);
}

START_TEST(test_official_2) {
    int input = -123, target = -321, ans = reverse(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on reverse(%d).", target, ans, input);
}

START_TEST(test_official_3) {
    int input = 120, target = 21, ans = reverse(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on reverse(%d).", target, ans, input);
}

START_TEST(test_own) {
    int input = 1123456789, target = 0, ans = reverse(input);
    ck_assert_msg(target == ans, "error, except %d but got %d on reverse(%d).", target, ans, input);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}