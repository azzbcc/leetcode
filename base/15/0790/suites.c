/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/8 下午1:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0790.c"

START_TEST(test_official) {
    int n = 3, target = 5;
    ck_assert_int_eq(target, numTilings(n));
}

START_TEST(test_own) {
    int arr[] = { 0, 1, 2, 5, 11, 24, 53, 117, 258, 569, 1255 };
    for (int i = 1; i < LEN(arr); ++i) {
        ck_assert_int_eq(arr[i], numTilings(i));
    }
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official);
}