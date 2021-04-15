/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/15 下午4:10
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1819.c"

START_TEST(test_official_1) {
    int arr[]  = { 6, 10, 3 };
    int target = 5, ans = countDifferentSubsequenceGCDs(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 5, 15, 40, 5, 6 };
    int target = 7, ans = countDifferentSubsequenceGCDs(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}