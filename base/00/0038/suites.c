/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/26 上午10:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0038.c"

START_TEST(test_official_1) {
    int n = 1;
    char *target = "1";
    char *ans = countAndSay(n);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_official_2) {
    int n = 4;
    char *target = "1211";
    char *ans = countAndSay(n);

    ck_assert_str_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}