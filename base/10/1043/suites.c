/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/19 下午4:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1043.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 15, 7, 9, 2, 5, 10 }, k = 3;
    int target = 84, ans = maxSumAfterPartitioning(arr, LEN(arr), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3 }, k = 4;
    int target = 83, ans = maxSumAfterPartitioning(arr, LEN(arr), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[] = { 1 }, k = 1;
    int target = 1, ans = maxSumAfterPartitioning(arr, LEN(arr), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}