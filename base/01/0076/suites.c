/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/10 下午3:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0076.c"

START_TEST(test_official_1) {
    char *s = "ADOBECODEBANC", *t = "ABC";

    char *target = "BANC", *ans = minWindow(s, t);

    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_official_2) {
    char *s = "a", *t = "a";

    char *target = "a", *ans = minWindow(s, t);

    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_failed_1) {
    char *s = "a", *t = "aa";

    char *target = "", *ans = minWindow(s, t);

    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_failed_2) {
    char *s = "ab", *t = "b";

    char *target = "b", *ans = minWindow(s, t);

    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_failed_3) {
    char *s = "aaaaaaaaaaaabbbbbcdd", *t = "abcdd";

    char *target = "abbbbbcdd", *ans = minWindow(s, t);

    ck_assert_str_eq(ans, target);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}