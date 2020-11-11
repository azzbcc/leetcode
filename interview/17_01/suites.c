/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/11 下午5:22
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "17_01.c"

START_TEST(test_official) {
    int a = 1, b = 1;

    int target = a + b, ans = add(a, b);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    int a = -1, b = 2;

    int target = a + b, ans = add(a, b);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}