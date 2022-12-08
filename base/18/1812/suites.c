/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/8 上午11:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1812.c"

START_TEST(test_official_1) {
    char *coordinates = "a1";
    ck_assert_int_eq(false, squareIsWhite(coordinates));
}

START_TEST(test_official_2) {
    char *coordinates = "h3";
    ck_assert_int_eq(true, squareIsWhite(coordinates));
}

START_TEST(test_official_3) {
    char *coordinates = "c7";
    ck_assert_int_eq(false, squareIsWhite(coordinates));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}