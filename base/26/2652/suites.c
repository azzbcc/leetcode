/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/17 17:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2652.c"

START_TEST(test_official_1) {
    int n      = 7;
    int target = 21, ans = sumOfMultiples(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 10;
    int target = 40, ans = sumOfMultiples(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n      = 9;
    int target = 30, ans = sumOfMultiples(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    ck_assert_int_eq(3045, sumOfMultiples(105));
    ck_assert_int_eq(12075, sumOfMultiples(210));
    ck_assert_int_eq(12503, sumOfMultiples(215));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}