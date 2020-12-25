/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/25 下午12:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0455.c"

START_TEST(test_official_1) {
    int g[] = { 1, 2, 3 }, s[] = { 1, 1 };
    int target = 1, ans = findContentChildren(g, LEN(g), s, LEN(s));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int g[] = { 1, 2 }, s[] = { 1, 2, 3 };
    int target = 2, ans = findContentChildren(g, LEN(g), s, LEN(s));

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}