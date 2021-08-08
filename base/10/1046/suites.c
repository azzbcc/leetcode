/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/30 上午11:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1046.c"

START_TEST(test_official) {
    int arr[]  = { 2, 7, 4, 1, 8, 1 };
    int target = 1, ans = lastStoneWeight(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int arr[]  = { 1, 3 };
    int target = 2, ans = lastStoneWeight(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int arr[]  = { 7, 6, 7, 6, 9 };
    int target = 3, ans = lastStoneWeight(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official);
}