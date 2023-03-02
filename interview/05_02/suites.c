/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/2 下午4:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "05_02.c"

START_TEST(test_official_1) {
    double num   = 0.625;
    char *target = "0.101", *ans = printBin(num);
    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_official_2) {
    double num   = 0.1;
    char *target = "ERROR", *ans = printBin(num);
    ck_assert_str_eq(ans, target);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}