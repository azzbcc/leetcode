/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/10 10:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2696.c"

START_TEST(test_official_1) {
    char *s    = "ABFCACDB";
    int target = 2, ans = minLength(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s    = "ACBBD";
    int target = 5, ans = minLength(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}