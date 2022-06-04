/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/6/4 上午10:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0929.c"

START_TEST(test_official_1) {
    char *emails[] = { "test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com",
                       "testemail+david@lee.tcode.com" };
    int target = 2, ans = numUniqueEmails(emails, LEN(emails));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *emails[] = { "a@leetcode.com", "b@leetcode.com", "c@leetcode.com" };
    int target = 3, ans = numUniqueEmails(emails, LEN(emails));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}