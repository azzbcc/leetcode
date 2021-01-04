/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/4 上午11:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0509.c"

START_TEST(test_official_1) {
    int target = 1, ans = fib(2);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int target = 2, ans = fib(3);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int target = 3, ans = fib(4);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_limit) {
    int target = 832040, ans = fib(30);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}