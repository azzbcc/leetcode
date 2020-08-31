/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/7 上午17:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdlib.h>

#include "0016.c"

START_TEST(test_official) {
    int arr[] = { -1, 2, 1, -4 }, input = 1;
    int target = 2, ans = threeSumClosest(arr, sizeof(arr) / sizeof(arr[0]), input);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    int arr[] = { -1, 0, 1, 1, 55 }, input = 3;
    int target = 2, ans = threeSumClosest(arr, sizeof(arr) / sizeof(arr[0]), input);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}