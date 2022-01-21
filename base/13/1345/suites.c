/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/21 下午2:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1345.c"

START_TEST(test_official_1) {
    int arr[]  = { 100, -23, -23, 404, 100, 23, 23, 23, 3, 404 };
    int target = 3, ans = minJumps(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 7 };
    int target = 0, ans = minJumps(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 7, 6, 9, 6, 9, 6, 9, 7 };
    int target = 1, ans = minJumps(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int arr[]  = { 6, 1, 9 };
    int target = 2, ans = minJumps(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int arr[]  = { 11, 22, 7, 7, 7, 7, 7, 7, 7, 22, 13 };
    int target = 3, ans = minJumps(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle_1) {
    int arr[50000] = { [49999] = 11 };
    for (int i = 0; i + 1 < LEN(arr); arr[i++] = 7) {}
    int target = 2, ans = minJumps(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle_2) {
    int arr[50000] = { [49999] = 11 };
    for (int i = 0; i + 1 < LEN(arr); arr[i++] = 7) {}
    for (int i = 49978; i + 1 < LEN(arr); arr[i++] = 1) {}
    int target = 4, ans = minJumps(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int arr[]  = { 7, 7, 2, 1, 7, 7, 7, 3, 4, 1 };
    int target = 3, ans = minJumps(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}
void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_tle_2);
    tcase_add_test(t, test_tle_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);

    set_execute_timeout(t, 0.1);
}