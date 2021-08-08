/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/20 下午2:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdbool.h>

#include "0263.c"

START_TEST(test_official_1) {
    fail_if(isUgly(6) != true);
}

START_TEST(test_official_2) {
    fail_if(isUgly(8) != true);
}

START_TEST(test_official_3) {
    fail_if(isUgly(14) != false);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}
