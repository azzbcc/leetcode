/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/24 下午3:53
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1375.c"

START_TEST(test_official_1) {
    int arr[]  = { 2, 1, 3, 5, 4 };
    int target = 3, ans = numTimesAllBlue(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 3, 2, 4, 1, 5 };
    int target = 2, ans = numTimesAllBlue(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 4, 1, 2, 3 };
    int target = 1, ans = numTimesAllBlue(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int arr[]  = { 2, 1, 4, 3, 6, 5 };
    int target = 3, ans = numTimesAllBlue(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int arr[]  = { 1, 2, 3, 4, 5, 6 };
    int target = 6, ans = numTimesAllBlue(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}