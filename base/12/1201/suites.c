/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/4 下午6:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1201.c"

START_TEST(test_official_1) {
    int n = 3, a = 2, b = 3, c = 5;

    int target = 4, ans = nthUglyNumber(n, a, b, c);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int n = 4, a = 2, b = 3, c = 4;

    int target = 6, ans = nthUglyNumber(n, a, b, c);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    int n = 5, a = 2, b = 11, c = 13;

    int target = 10, ans = nthUglyNumber(n, a, b, c);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_4) {
    int n = 1000000000, a = 2, b = 217983653, c = 336916467;

    int target = 1999999984, ans = nthUglyNumber(n, a, b, c);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed_1) {
    int n = 7, a = 7, b = 7, c = 7;

    int target = 49, ans = nthUglyNumber(n, a, b, c);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed_2) {
    int n = 19, a = 5, b = 17, c = 18;

    int target = 65, ans = nthUglyNumber(n, a, b, c);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}