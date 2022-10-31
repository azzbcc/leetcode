/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/31 下午1:55
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0481.c"

START_TEST(test_official_1) {
    int n = 6, target = 3;
    int ans = magicalString(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 1, target = 1;
    int ans = magicalString(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}