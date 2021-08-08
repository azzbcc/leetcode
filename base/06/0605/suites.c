/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/1 上午12:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0605.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 0, 0, 0, 1 }, n = 1;
    bool target = true, ans = canPlaceFlowers(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 0, 0, 0, 1 }, n = 2;
    bool target = false, ans = canPlaceFlowers(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int arr[] = { 1, 0, 0, 1 }, n = 1;
    bool target = false, ans = canPlaceFlowers(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int arr[] = { 0, 0, 1, 0, 1 }, n = 1;
    bool target = true, ans = canPlaceFlowers(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int arr[] = { 0, 1, 0 }, n = 1;
    bool target = false, ans = canPlaceFlowers(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}