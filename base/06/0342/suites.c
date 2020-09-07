/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/7 下午4:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0342.c"

START_TEST(test_official_1) {
    bool target = true, ans = isPowerOfFour(16);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    bool target = false, ans = isPowerOfFour(5);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    bool target = false, ans = isPowerOfFour(-2147483648);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}