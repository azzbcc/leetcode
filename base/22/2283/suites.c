/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/1/11 下午12:57
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2283.c"

START_TEST(test_official_1) {
    char *num = "1210";
    ck_assert_int_eq(true, digitCount(num));
}

START_TEST(test_official_2) {
    char *num = "030";
    ck_assert_int_eq(false, digitCount(num));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}