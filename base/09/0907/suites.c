/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/28 下午12:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0907.c"

START_TEST(test_official_1) {
    int arr[]  = { 3, 1, 2, 4 };
    int target = 17, ans = sumSubarrayMins(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 11, 81, 94, 43, 3 };
    int target = 444, ans = sumSubarrayMins(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_overflow) {
#include "overflow.c"
    int target = 508796209, ans = sumSubarrayMins(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_overflow);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}