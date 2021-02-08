/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/6 下午12:01
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1423.c"

START_TEST(test_official_1) {
    int k = 3, arr[] = { 1, 2, 3, 4, 5, 6, 1 };
    int target = 12, ans = maxScore(arr, LEN(arr), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int k = 2, arr[] = { 2, 2, 2 };
    int target = 4, ans = maxScore(arr, LEN(arr), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int k = 7, arr[] = { 9, 7, 7, 9, 7, 7, 9 };
    int target = 55, ans = maxScore(arr, LEN(arr), k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int k = 1, arr[] = { 1, 1000, 1 };
    int target = 1, ans = maxScore(arr, LEN(arr), k);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}