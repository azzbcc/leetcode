/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/28 上午10:48
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0869.c"

START_TEST(test_official_1) {
    int num     = 1;
    bool target = true, ans = reorderedPowerOf2(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int num     = 10;
    bool target = false, ans = reorderedPowerOf2(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int num     = 16;
    bool target = true, ans = reorderedPowerOf2(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int num     = 24;
    bool target = false, ans = reorderedPowerOf2(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int num     = 46;
    bool target = true, ans = reorderedPowerOf2(num);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}