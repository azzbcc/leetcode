/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/6 下午2:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1011.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, d = 5;
    int target = 15, ans = shipWithinDays(arr, LEN(arr), d);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[] = { 3, 2, 2, 4, 1, 4 }, d = 3;
    int target = 6, ans = shipWithinDays(arr, LEN(arr), d);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    int arr[] = { 1, 2, 3, 1, 1 }, d = 4;
    int target = 3, ans = shipWithinDays(arr, LEN(arr), d);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}