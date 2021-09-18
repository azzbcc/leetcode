/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/18 上午11:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0292.c"

START_TEST(test_official_1) {
    int n       = 4;
    bool target = false, ans = canWinNim(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n       = 1;
    bool target = true, ans = canWinNim(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n       = 2;
    bool target = true, ans = canWinNim(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}