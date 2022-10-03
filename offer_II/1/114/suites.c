/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/31 上午10:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "114.c"

START_TEST(test_official_1) {
    char *words[] = { "wrt", "wrf", "er", "ett", "rftt" };
    char *target = "wertf", *ans = alienOrder(words, LEN(words));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *words[] = { "z", "x" };
    char *target = "zx", *ans = alienOrder(words, LEN(words));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    char *words[] = { "z", "x", "z" };
    char *target = "", *ans = alienOrder(words, LEN(words));
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed) {
    char *words[] = { "z", "z" };
    char *target = "z", *ans = alienOrder(words, LEN(words));
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}