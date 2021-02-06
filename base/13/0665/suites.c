/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/7 上午1:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0665.c"

START_TEST(test_official_1) {
    int arr[]   = { 4, 2, 3 };
    bool target = true, ans = checkPossibility(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]   = { 4, 2, 1 };
    bool target = false, ans = checkPossibility(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int arr[]   = { 3, 4, 2, 3 };
    bool target = false, ans = checkPossibility(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int arr[]   = { 5, 7, 1, 8 };
    bool target = true, ans = checkPossibility(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}