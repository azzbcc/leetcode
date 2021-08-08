/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/12 上午9:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0275.c"

START_TEST(test_official) {
    int arr[]  = { 0, 1, 3, 5, 6 };
    int target = 3, ans = hIndex(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int arr[]  = { 6, 6, 6, 6, 6, 6 };
    int target = 6, ans = hIndex(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official);
}