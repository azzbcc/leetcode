/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/4 下午8:57
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "offer_10_I.c"

START_TEST(test_official_1) {
    int n      = 2;
    int target = 1, ans = fib(n);
    ck_assert_int_eq(ans, target);
}
START_TEST(test_official_2) {
    int n      = 5;
    int target = 5, ans = fib(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}