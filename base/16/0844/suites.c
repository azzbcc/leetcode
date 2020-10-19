/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/19 上午11:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0844.c"

START_TEST(test_official_1) {
    char *S = "ab#c", *T = "ad#c";

    bool target = true, ans = backspaceCompare(S, T);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    char *S = "ab##", *T = "c#d#";

    bool target = true, ans = backspaceCompare(S, T);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    char *S = "a##c", *T = "#a#c";

    bool target = true, ans = backspaceCompare(S, T);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_4) {
    char *S = "a#c", *T = "b";

    bool target = false, ans = backspaceCompare(S, T);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    char *S = "nzp#o#g", *T = "b#nzp#o#g";

    bool target = true, ans = backspaceCompare(S, T);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}