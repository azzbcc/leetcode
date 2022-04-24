/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/24 下午12:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0868.c"

START_TEST(test_official_1) {
    int n = 22, target = 2, ans = binaryGap(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 8, target = 0, ans = binaryGap(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n = 5, target = 2, ans = binaryGap(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}