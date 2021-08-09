/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/9 上午11:37
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0313.c"

START_TEST(test_official_1) {
    int n = 12, primes[] = { 2, 7, 13, 19 };
    int target = 32, ans = nthSuperUglyNumber(n, primes, LEN(primes));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 1, primes[] = { 2, 3, 5 };
    int target = 1, ans = nthSuperUglyNumber(n, primes, LEN(primes));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_limit) {
    int n = 100000, primes[] = { 7,   19,  29,  37,  41,  47,  53,  59,  61,  79,  83,  89,  101, 103, 109,
                                 127, 131, 137, 139, 157, 167, 179, 181, 199, 211, 229, 233, 239, 241, 251 };
    int target = 1092889481, ans = nthSuperUglyNumber(n, primes, LEN(primes));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}