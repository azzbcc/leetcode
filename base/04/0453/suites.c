/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/20 上午10:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0453.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 2, 3 };
    int target = 3, ans = minMoves(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, 1, 1 };
    int target = 0, ans = minMoves(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}