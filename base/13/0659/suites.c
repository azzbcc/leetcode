/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/4 上午11:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0659.c"

START_TEST(test_official_1) {
    int arr[]   = { 1, 2, 3, 3, 4, 5 };
    bool target = true, ans = isPossible(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]   = { 1, 2, 3, 3, 4, 4, 5, 5 };
    bool target = true, ans = isPossible(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]   = { 1, 2, 3, 4, 4, 5 };
    bool target = false, ans = isPossible(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_own_1) {
    int arr[]   = { 1, 2, 3, 5, 6, 7 };
    bool target = true, ans = isPossible(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_own_2) {
    int arr[]   = { 1, 2, 2, 3, 3, 3, 4, 4, 5 };
    bool target = true, ans = isPossible(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int arr[]   = { 1 };
    bool target = false, ans = isPossible(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own_1);
    tcase_add_test(t, test_own_2);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}