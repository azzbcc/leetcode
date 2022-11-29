/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/29 下午2:22
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1758.c"

START_TEST(test_official_1) {
    char *s = "0100";
    ck_assert_int_eq(1, minOperations(s));
}

START_TEST(test_official_2) {
    char *s = "10";
    ck_assert_int_eq(0, minOperations(s));
}

START_TEST(test_official_3) {
    char *s = "1111";
    ck_assert_int_eq(2, minOperations(s));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}