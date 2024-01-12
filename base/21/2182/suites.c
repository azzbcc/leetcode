/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/13 00:28
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2182.c"

START_TEST(test_official_1) {
    int repeatLimit = 3;
    char *s         = "cczazcc";
    char *target = "zzcccac", *ans = repeatLimitedString(s, repeatLimit);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int repeatLimit = 2;
    char *s         = "aababab";
    char *target = "bbabaa", *ans = repeatLimitedString(s, repeatLimit);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}