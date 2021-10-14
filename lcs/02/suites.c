/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/14 上午11:42
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "lcs_02.c"

START_TEST(test_official_1) {
    int arr[]  = { 2, 1, 6, 2 };
    int target = 1, ans = halfQuestions(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, 5, 1, 3, 4, 5, 2, 5, 3, 3, 8, 6 };
    int target = 2, ans = halfQuestions(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}