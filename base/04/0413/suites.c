/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/10 上午10:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0413.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 2, 3, 4 };
    int target = 3, ans = numberOfArithmeticSlices(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 1 };
    int target = 0, ans = numberOfArithmeticSlices(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int arr[]  = { 1, 2, 3, 4, 6, 1, 3, 5, 7 };
    int target = 6, ans = numberOfArithmeticSlices(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}