/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/17 下午12:58
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1220.c"

START_TEST(test_official_1) {
    int n      = 1;
    int target = 5, ans = countVowelPermutation(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 2;
    int target = 10, ans = countVowelPermutation(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n      = 5;
    int target = 68, ans = countVowelPermutation(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_limit) {
    int n      = 144;
    int target = 18208803, ans = countVowelPermutation(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}