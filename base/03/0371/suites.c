/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/26 上午10:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0371.c"

START_TEST(test_official_1) {
    int a = 1, b = 2;
    ck_assert_int_eq(a + b, getSum(a, b));
}

START_TEST(test_official_2) {
    int a = 2, b = 3;
    ck_assert_int_eq(a + b, getSum(a, b));
}

START_TEST(test_failed_1) {
    int a = -1, b = 1;
    ck_assert_int_eq(a + b, getSum(a, b));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}