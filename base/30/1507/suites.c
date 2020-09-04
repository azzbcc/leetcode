/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/4 下午5:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1507.c"

START_TEST(test_official_1) {
    char *input  = "20th Oct 2052";
    char *target = "2052-10-20", *ans = reformatDate(input);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_official_2) {
    char *input  = "6th Jun 1933";
    char *target = "1933-06-06", *ans = reformatDate(input);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_official_3) {
    char *input  = "26th May 1960";
    char *target = "1960-05-26", *ans = reformatDate(input);

    ck_assert_str_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}
