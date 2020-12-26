/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/27 上午1:01
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0205.c"

START_TEST(test_official_1) {
    char *s = "egg", *t = "add";
    bool target = true, ans = isIsomorphic(s, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s = "foo", *t = "bar";
    bool target = false, ans = isIsomorphic(s, t);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s = "paper", *t = "title";
    bool target = true, ans = isIsomorphic(s, t);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}