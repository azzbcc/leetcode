/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/8 下午2:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0132.c"

START_TEST(test_official_1) {
    char *s = "aab";
    int target = 1, ans = minCut(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s = "a";
    int target = 0, ans = minCut(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s = "ab";
    int target = 1, ans = minCut(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    char *s = "abcdcba";
    int target = 0, ans = minCut(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}