/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/8 下午7:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0122.c"

START_TEST(test_official_1) {
    int arr[] = { 7, 1, 5, 3, 6, 4 };

    int target = 7, ans = maxProfit(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 2, 3, 4, 5 };

    int target = 4, ans = maxProfit(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    int arr[] = { 7, 6, 4, 3, 1 };

    int target = 0, ans = maxProfit(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}