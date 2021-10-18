/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/18 下午8:01
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0859.c"

START_TEST(test_official_1) {
    char *A = "ab", *B = "ba";
    bool target = true, ans = buddyStrings(A, B);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *A = "ab", *B = "ab";
    bool target = false, ans = buddyStrings(A, B);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *A = "aa", *B = "aa";
    bool target = true, ans = buddyStrings(A, B);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *A = "aaaaaaabc", *B = "aaaaaaacb";
    bool target = true, ans = buddyStrings(A, B);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    char *A = "", *B = "aa";
    bool target = false, ans = buddyStrings(A, B);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}