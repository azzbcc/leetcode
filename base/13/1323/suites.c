/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/3 下午7:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1323.c"

START_TEST(test_official_1) {
    int num    = 9669;
    int target = 9969, ans = maximum69Number(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int num    = 9996;
    int target = 9999, ans = maximum69Number(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int num    = 9999;
    int target = 9999, ans = maximum69Number(num);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}