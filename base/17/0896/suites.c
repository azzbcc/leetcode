/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/28 下午1:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0896.c"

START_TEST(test_official_1) {
    int arr[]   = { 1, 2, 2, 3 };
    bool target = true, ans = isMonotonic(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]   = { 6, 5, 4, 4 };
    bool target = true, ans = isMonotonic(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]   = { 1, 3, 2 };
    bool target = false, ans = isMonotonic(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int arr[]   = { 1, 2, 4, 5 };
    bool target = true, ans = isMonotonic(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int arr[]   = { 1, 1, 1 };
    bool target = true, ans = isMonotonic(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}