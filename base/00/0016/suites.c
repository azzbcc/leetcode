/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/7 上午17:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0016.c"

START_TEST(test_official_1) {
    int arr[] = { -1, 2, 1, -4 }, input = 1;
    int target = 2, ans = threeSumClosest(arr, LEN(arr), input);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int arr[] = { 0, 0, 0 }, input = 1;
    int target = 0, ans = threeSumClosest(arr, LEN(arr), input);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    int arr[] = { -1, 0, 1, 1, 55 }, input = 3;
    int target = 2, ans = threeSumClosest(arr, LEN(arr), input);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}