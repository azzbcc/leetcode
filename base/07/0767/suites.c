/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/30 下午12:16
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0767.c"

START_TEST(test_official_1) {
    char s[]     = "aab";
    char *target = "aba", *ans = reorganizeString(s);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char s[]     = "aaab";
    char *target = "", *ans = reorganizeString(s);

    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}