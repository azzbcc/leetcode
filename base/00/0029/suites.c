/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/13 下午2:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0029.c"

START_TEST(test_official_1) {
    int dividend = 10, divisor = 3;
    int target = 3, ans = divide(dividend, divisor);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int dividend = 7, divisor = -3;
    int target = -2, ans = divide(dividend, divisor);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_own) {
    int dividend = INT32_MIN, divisor = -1;
    int target = INT32_MAX, ans = divide(dividend, divisor);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}