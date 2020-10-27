/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/27 下午1:59
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0044.c"

START_TEST(test_official_1) {
    char *s = "aa", *p = "a";

    bool target = false, ans = isMatch(s, p);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    char *s = "aa", *p = "*";

    bool target = true, ans = isMatch(s, p);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    char *s = "cb", *p = "?a";

    bool target = false, ans = isMatch(s, p);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_4) {
    char *s = "adceb", *p = "*a*b";

    bool target = true, ans = isMatch(s, p);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_5) {
    char *s = "acdcb", *p = "a*c?b";

    bool target = false, ans = isMatch(s, p);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}