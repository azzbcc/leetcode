/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/3 上午11:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0204.c"

START_TEST(test_official_1) {
    int target = 4, ans = countPrimes(10);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int target = 0, ans = countPrimes(0);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int target = 0, ans = countPrimes(1);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int target = 0, ans = countPrimes(2);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}