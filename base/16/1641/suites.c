/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/25 16:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1641.c"

START_TEST(test_official_1) {
    int n = 1, target = 5, ans = countVowelStrings(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 2, target = 15, ans = countVowelStrings(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n = 33, target = 66045, ans = countVowelStrings(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}