/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/27 下午5:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0560.c"

START_TEST(test_official) {
    int arr[] = { 1, 1, 1 }, k = 2;
    int target = 2, ans = subarraySum(arr, sizeof(arr) / sizeof(arr[0]), k);
    ck_assert_int_eq(target, ans);
}

START_TEST(test_own) {
    int arr[] = { 1, -1, 1, -1, 1 }, k = 0;
    int target = 6, ans = subarraySum(arr, sizeof(arr) / sizeof(arr[0]), k);
    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official);
}