/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/19 下午7:56
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdbool.h>
#include <stdio.h>

#include "0202.c"

START_TEST(test_official) {
    bool target = true, ans = isHappy(19);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}
