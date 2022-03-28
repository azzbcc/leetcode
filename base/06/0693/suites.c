/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/28 上午10:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0693.c"

START_TEST(test_official_1) {
    int n       = 5;
    bool target = true, ans = hasAlternatingBits(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n       = 7;
    bool target = false, ans = hasAlternatingBits(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n       = 11;
    bool target = false, ans = hasAlternatingBits(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}
