/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/11 下午5:57
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "08_03.c"

START_TEST(test_official_1) {
    int target = 4, ans = waysToStep(3);
    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    int target = 13, ans = waysToStep(5);
    ck_assert_int_eq(target, ans);
}

START_TEST(test_own) {
    int target = 746580045, ans = waysToStep(1000000);
    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}