/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/3 上午10:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1053.c"

START_TEST(test_official_1) {
    int arr[]    = { 3, 2, 1 };
    int target[] = { 3, 1, 2 };
    int len, *ans = prevPermOpt1(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int arr[]    = { 1, 1, 5 };
    int target[] = { 1, 1, 5 };
    int len, *ans = prevPermOpt1(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int arr[]    = { 1, 9, 4, 6, 7 };
    int target[] = { 1, 7, 4, 6, 9 };
    int len, *ans = prevPermOpt1(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}