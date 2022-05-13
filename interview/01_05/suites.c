/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/13 上午11:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "01_05.c"

START_TEST(test_official_1) {
    char *first = "pale", *second = "ple";
    bool target = true, ans = oneEditAway(first, second);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *first = "pales", *second = "pal";
    bool target = false, ans = oneEditAway(first, second);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    char *first = "azbzc", *second = "abcd";
    bool target = false, ans = oneEditAway(first, second);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}