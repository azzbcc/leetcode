/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/10 上午11:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0860.c"

START_TEST(test_official_1) {
    int arr[]   = { 5, 5, 5, 10, 20 };
    bool target = true, ans = lemonadeChange(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]   = { 5, 5, 10 };
    bool target = true, ans = lemonadeChange(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]   = { 10, 10 };
    bool target = false, ans = lemonadeChange(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int arr[]   = { 5, 5, 10, 10, 20 };
    bool target = false, ans = lemonadeChange(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}