/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/13 下午2:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1234.c"

START_TEST(test_official_1) {
    char *s    = "QWER";
    int target = 0, ans = balancedString(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s    = "QQWE";
    int target = 1, ans = balancedString(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s    = "QQQW";
    int target = 2, ans = balancedString(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *s    = "QQQQ";
    int target = 3, ans = balancedString(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    char *s    = "QWERQQQQ";
    int target = 3, ans = balancedString(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}