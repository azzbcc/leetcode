/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/4 上午11:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0367.c"

START_TEST(test_official_1) {
    int num = 16;
    bool target = true, ans = isPerfectSquare(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int num = 14;
    bool target = false, ans = isPerfectSquare(num);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}