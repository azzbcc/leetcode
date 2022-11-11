/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/11 上午11:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1704.c"

START_TEST(test_official_1) {
    char *s = "book";
    ck_assert_int_eq(true, halvesAreAlike(s));
}

START_TEST(test_official_2) {
    char *s = "textbook";
    ck_assert_int_eq(false, halvesAreAlike(s));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}