/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/13 下午2:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0670.c"

START_TEST(test_official_1) {
    int num    = 2736;
    int target = 7236, ans = maximumSwap(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int num    = 9973;
    int target = 9973, ans = maximumSwap(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int num    = 9793;
    int target = 9973, ans = maximumSwap(num);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}