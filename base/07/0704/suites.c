/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/6 上午10:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0704.c"

START_TEST(test_official_1) {
    int arr[] = { -1, 0, 3, 5, 9, 12 }, key = 9;
    int target = 4, ans = search(arr, LEN(arr), key);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[] = { -1, 0, 3, 5, 9, 12 }, key = 2;
    int target = -1, ans = search(arr, LEN(arr), key);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}