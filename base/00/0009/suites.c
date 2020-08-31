/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/3 下午5:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdbool.h>

#include "0009.c"

START_TEST(test_official_1) {
    int input   = 121;
    bool target = true, ans = isPalindrome(input);

    ck_assert_msg(target == ans, "error, except %d but got %d on isPalindrome(%d).", target, ans, input);
}

START_TEST(test_official_2) {
    int input   = -121;
    bool target = false, ans = isPalindrome(input);

    ck_assert_msg(target == ans, "error, except %d but got %d on isPalindrome(%d).", target, ans, input);
}

START_TEST(test_official_3) {
    int input   = 10;
    bool target = false, ans = isPalindrome(input);

    ck_assert_msg(target == ans, "error, except %d but got %d on isPalindrome(%d).", target, ans, input);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}