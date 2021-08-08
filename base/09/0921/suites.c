/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/21 下午5:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0921.c"

START_TEST(test_official_1) {
    char *str = "())";
    int target = 1, ans = minAddToMakeValid(str);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    char *str = "(((";
    int target = 3, ans = minAddToMakeValid(str);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    char *str = "()";
    int target = 0, ans = minAddToMakeValid(str);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_4) {
    char *str = "()))((";
    int target = 4, ans = minAddToMakeValid(str);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}