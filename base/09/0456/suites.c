/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/24 下午1:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0456.c"

START_TEST(test_official_1) {
    int arr[]   = { 1, 2, 3, 4 };
    bool target = false, ans = find132pattern(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]   = { 3, 1, 4, 2 };
    bool target = true, ans = find132pattern(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]   = { -1, 3, 2, 0 };
    bool target = true, ans = find132pattern(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int arr[]   = { 3, 5, 0, 3, 4 };
    bool target = true, ans = find132pattern(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}