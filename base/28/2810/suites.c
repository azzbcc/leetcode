/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/1 16:15
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2810.c"

START_TEST(test_official_1) {
    char *s      = "string";
    char *target = "rtsng", *ans = finalString(s);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s      = "poiinter";
    char *target = "ponter", *ans = finalString(s);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_own) {
    char *s      = "abci123ixyz";
    char *target = "321abcxyz", *ans = finalString(s);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}