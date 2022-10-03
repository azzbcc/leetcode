/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/25 下午6:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0467.c"

START_TEST(test_official_1) {
    char *p    = "a";
    int target = 1, ans = findSubstringInWraproundString(p);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *p    = "cac";
    int target = 2, ans = findSubstringInWraproundString(p);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *p    = "zab";
    int target = 6, ans = findSubstringInWraproundString(p);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}