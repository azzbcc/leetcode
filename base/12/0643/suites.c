/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/4 下午12:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0643.c"

START_TEST(test_official) {
    int arr[] = { 1, 12, -5, -6, 50, 3 }, k = 4;
    double target = 12.75, ans = findMaxAverage(arr, LEN(arr), k);
    ck_assert_double_eq_tol(ans, target, 0.00001);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}