/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/3 上午10:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */

#include <common.h>

#include "0415.c"

START_TEST(test_own) {
    char *num1 = "987654321", *num2 = "12345689";
    char *target = "1000000010", *ans = addStrings(num1, num2);

    ck_assert_msg(!strcmp(target, ans), "error, except %s but got %s on addStrings().", target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
}