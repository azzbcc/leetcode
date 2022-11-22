/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/22 下午1:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0878.c"

START_TEST(test_official_1) {
    int n = 1, a = 2, b = 3;
    int target = 2, ans = nthMagicalNumber(n, a, b);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 4, a = 2, b = 3;
    int target = 6, ans = nthMagicalNumber(n, a, b);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_overflow_1) {
    int n = 1000000000, a = 40000, b = 40000;
    int target = 999720007, ans = nthMagicalNumber(n, a, b);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_overflow_2) {
    int n = 307673195, a = 37340, b = 36427;
    int target = 239828629, ans = nthMagicalNumber(n, a, b);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_overflow_2);
    tcase_add_test(t, test_overflow_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}