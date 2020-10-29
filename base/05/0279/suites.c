/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/29 下午2:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0279.c"

START_TEST(test_official_1) {
    int n = 12;

    int target = 3, ans = numSquares(n);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int n = 13;

    int target = 2, ans = numSquares(n);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}