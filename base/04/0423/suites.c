/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/24 上午11:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0423.c"

START_TEST(test_official_1) {
    char *s      = "owoztneoer";
    char *target = "012", *ans = originalDigits(s);
    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_official_2) {
    char *s      = "fviefuro";
    char *target = "45", *ans = originalDigits(s);
    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_failed) {
    char *s      = "nnei";
    char *target = "9", *ans = originalDigits(s);
    ck_assert_str_eq(ans, target);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}