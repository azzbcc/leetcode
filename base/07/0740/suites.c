/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/2 下午6:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0740.c"

START_TEST(test_official_1) {
    int arr[]  = { 3, 4, 2 };
    int target = 6, ans = deleteAndEarn(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[]  = { 2, 2, 3, 3, 3, 4 };
    int target = 9, ans = deleteAndEarn(arr, LEN(arr));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}