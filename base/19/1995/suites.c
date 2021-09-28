/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/28 下午2:39
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1995.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 2, 3, 6 };
    int target = 1, ans = countQuadruplets(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 3, 3, 6, 4 };
    int target = 0, ans = countQuadruplets(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 1, 1, 1, 3, 5 };
    int target = 4, ans = countQuadruplets(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int arr[]  = { 1, 1, 0, 1, 3 };
    int target = 1, ans = countQuadruplets(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}