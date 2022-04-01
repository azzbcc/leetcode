/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/1 上午11:27
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0954.c"

START_TEST(test_official_1) {
    int arr[]   = { 3, 1, 3, 6 };
    bool target = false, ans = canReorderDoubled(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]   = { 2, 1, 2, 6 };
    bool target = false, ans = canReorderDoubled(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]   = { 4, -2, 2, -4 };
    bool target = true, ans = canReorderDoubled(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int arr[]   = { 1, 2, 2, 4 };
    bool target = true, ans = canReorderDoubled(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int arr[]   = { 2, 4, 0, 0, 8, 1 };
    bool target = true, ans = canReorderDoubled(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int arr[]   = { 1, 2, 4, 16, 8, 4 };
    bool target = false, ans = canReorderDoubled(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    //    tcase_add_test(t, test_failed_2);
    //    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}