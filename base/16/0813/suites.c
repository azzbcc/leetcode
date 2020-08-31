/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/31 下午3:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0813.c"

START_TEST(test_official) {
    int arr[] = { 9, 1, 2, 3, 9 }, K = 3;

    double target = 20, ans = largestSumOfAverages(arr, sizeof(arr) / sizeof(arr[0]), K);

    ck_assert_double_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}