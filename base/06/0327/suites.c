/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/7 下午12:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0327.c"

START_TEST(test_official) {
    int arr[] = { -2, 5, -1 };

    int target = 3, ans = countRangeSum(arr, LEN(arr), -2, 2);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_tle) {
    int arr[10000] = {};
    for (int i = 0; i < LEN(arr); arr[i++] = 1) {}

    int target = 9999 + 9998 + 9997 + 9996, ans = countRangeSum(arr, LEN(arr), 2, 5);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_official);

    set_execute_timeout(t, 0.1);
}