/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/5 上午12:10
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0011.c"

START_TEST(test_official) {
    int arr[]  = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    int target = 49, ans = maxArea(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_msg(target == ans, "error, except %d but got %d on rob().", target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}