/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/13 13:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2864.c"

START_TEST(test_official_1) {
    char s[]     = "010";
    char *target = "001", *ans = maximumOddBinaryNumber(s);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char s[]     = "0101";
    char *target = "1001", *ans = maximumOddBinaryNumber(s);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}