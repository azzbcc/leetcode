/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/19 上午7:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1239.c"

START_TEST(test_official_1) {
    char *arr[] = { "un", "iq", "ue" };
    int target = 4, ans = maxLength(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *arr[] = { "cha", "r", "act", "ers" };
    int target = 6, ans = maxLength(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *arr[] = { "abcdefghijklmnopqrstuvwxyz" };
    int target = 26, ans = maxLength(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}