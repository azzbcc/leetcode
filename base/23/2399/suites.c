/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/9 上午1:04
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2399.c"

START_TEST(test_official_1) {
    char *s        = "abaccb";
    int distance[] = { 1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    ck_assert_int_eq(true, checkDistances(s, distance, LEN(distance)));
}

START_TEST(test_official_2) {
    char *s        = "aa";
    int distance[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    ck_assert_int_eq(false, checkDistances(s, distance, LEN(distance)));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}