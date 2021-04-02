/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/2 下午1:30
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "17_21.c"

START_TEST(test_official) {
    int arr[]  = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int target = 6, ans = trap(arr, LEN(arr));
    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}