/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/7/28 下午7:00
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdbool.h>

#include "0866.c"

START_TEST(test_official_1) {
    int ans = primePalindrome(6), target = 7;
    ck_assert_msg(ans == target, "error, except %d but got %d on primePalindrome(6).", target, ans);
}

START_TEST(test_official_2) {
    int ans = primePalindrome(8), target = 11;
    ck_assert_msg(ans == target, "error, except %d but got %d on primePalindrome(6).", target, ans);
}

START_TEST(test_official_3) {
    int ans = primePalindrome(13), target = 101;
    ck_assert_msg(ans == target, "error, except %d but got %d on primePalindrome(6).", target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}