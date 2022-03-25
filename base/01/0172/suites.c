/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/25 下午8:00
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0172.c"

START_TEST(test_official_1) {
    int n      = 3;
    int target = 0, ans = trailingZeroes(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 5;
    int target = 1, ans = trailingZeroes(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n      = 0;
    int target = 0, ans = trailingZeroes(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}

