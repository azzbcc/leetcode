/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/5/11 10:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1016.c"

START_TEST(test_official_1) {
    int n   = 3;
    char *s = "0110";
    ck_assert_int_eq(true, queryString(s, n));
}

START_TEST(test_official_2) {
    int n   = 4;
    char *s = "0110";
    ck_assert_int_eq(false, queryString(s, n));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}