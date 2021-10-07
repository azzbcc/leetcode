/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/7 下午1:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0434.c"

START_TEST(test_official) {
    char *str  = "Hello, my name is John";
    int target = 5, ans = countSegments(str);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own_1) {
    char *str  = " Hello, my name is John";
    int target = 5, ans = countSegments(str);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own_2) {
    char *str  = "Hello, my name is John ";
    int target = 5, ans = countSegments(str);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own_3) {
    char *str  = "Hello,  my name is John";
    int target = 5, ans = countSegments(str);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own_1);
    tcase_add_test(t, test_own_2);
    tcase_add_test(t, test_own_3);
    tcase_add_test(t, test_official);
}