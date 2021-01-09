/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/9 下午1:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0123.c"

START_TEST(test_official_1) {
    int arr[]  = { 3, 3, 5, 0, 0, 3, 1, 4 };
    int target = 6, ans = maxProfit(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, 2, 3, 4, 5 };
    int target = 4, ans = maxProfit(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 7, 6, 4, 3, 1 };
    int target = 0, ans = maxProfit(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int arr[]  = { 1 };
    int target = 0, ans = maxProfit(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}
