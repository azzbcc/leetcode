/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/13 上午1:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0217.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3, 1 };

    bool target = true, ans = containsDuplicate(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 2, 3, 4 };

    bool target = false, ans = containsDuplicate(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[] = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };

    bool target = true, ans = containsDuplicate(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int arr[] = {};

    bool target = false, ans = containsDuplicate(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}