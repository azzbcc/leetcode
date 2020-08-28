/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/28 下午5:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0523.c"

START_TEST(test_official_1) {
    int arr[] = { 23, 2, 4, 6, 7 }, k = 6;
    bool target = true, ans = checkSubarraySum(arr, sizeof(arr) / sizeof(arr[0]), k);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[] = { 23, 2, 6, 4, 7 }, k = 6;
    bool target = true, ans = checkSubarraySum(arr, sizeof(arr) / sizeof(arr[0]), k);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    int arr[] = { 0, 0 }, k = 0;
    bool target = true, ans = checkSubarraySum(arr, sizeof(arr) / sizeof(arr[0]), k);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_limit) {
    int arr[] = { 23, 2, 6, 4, 7 }, k = 0;
    bool target = false, ans = checkSubarraySum(arr, sizeof(arr) / sizeof(arr[0]), k);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
//    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}