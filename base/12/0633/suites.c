/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/28 上午10:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0633.c"

START_TEST(test_official_1) {
    int c       = 5;
    bool target = true, ans = judgeSquareSum(c);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int c       = 3;
    bool target = false, ans = judgeSquareSum(c);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int c       = 4;
    bool target = true, ans = judgeSquareSum(c);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int c       = 2;
    bool target = true, ans = judgeSquareSum(c);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    int c       = 1;
    bool target = true, ans = judgeSquareSum(c);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int c       = 2147482647;
    bool target = false, ans = judgeSquareSum(c);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}