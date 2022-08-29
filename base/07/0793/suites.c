/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/28 下午8:56
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0793.c"

START_TEST(test_official_1) {
    int target = 5, ans = preimageSizeFZF(0);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int target = 0, ans = preimageSizeFZF(5);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int target = 5, ans = preimageSizeFZF(3);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_limit) {
    int target = 5, ans = preimageSizeFZF(1000000000);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}