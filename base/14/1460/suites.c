/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/24 上午10:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1460.c"

START_TEST(test_official_1) {
    int target[] = { 1, 2, 3, 4 }, arr[] = { 2, 4, 1, 3 };
    ck_assert_int_eq(true, canBeEqual(target, LEN(target), arr, LEN(arr)));
}

START_TEST(test_official_2) {
    int target[] = { 7 }, arr[] = { 7 };
    ck_assert_int_eq(true, canBeEqual(target, LEN(target), arr, LEN(arr)));
}

START_TEST(test_official_3) {
    int target[] = { 3, 7, 9 }, arr[] = { 3, 7, 11 };
    ck_assert_int_eq(false, canBeEqual(target, LEN(target), arr, LEN(arr)));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}