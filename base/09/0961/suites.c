/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/21 上午10:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0961.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 2, 3, 3 };
    int target = 3, ans = repeatedNTimes(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 2, 1, 2, 5, 3, 2 };
    int target = 2, ans = repeatedNTimes(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 5, 1, 5, 2, 5, 3, 5, 4 };
    int target = 5, ans = repeatedNTimes(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}