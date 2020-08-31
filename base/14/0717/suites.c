/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/26 下午1:53
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0717.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 0, 0 };

    bool target = true, ans = isOneBitCharacter(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 1, 1, 0 };

    bool target = false, ans = isOneBitCharacter(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}