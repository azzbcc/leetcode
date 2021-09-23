/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/23 上午10:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0326.c"

START_TEST(test_official_1) {
    int n       = 27;
    bool target = true, ans = isPowerOfThree(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n       = 0;
    bool target = false, ans = isPowerOfThree(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n       = 9;
    bool target = true, ans = isPowerOfThree(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int n       = 45;
    bool target = false, ans = isPowerOfThree(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}