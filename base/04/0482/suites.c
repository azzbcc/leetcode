/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/8 下午3:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0482.c"

START_TEST(test_official_1) {
    int K        = 4;
    char *S      = "5F3Z-2e-9-w";
    char *target = "5F3Z-2E9W", *ans = licenseKeyFormatting(S, K);
    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_official_2) {
    int K        = 2;
    char *S      = "2-5g-3-J";
    char *target = "2-5G-3J", *ans = licenseKeyFormatting(S, K);
    ck_assert_str_eq(ans, target);
    free(ans);
}
START_TEST(test_failed) {
    int K        = 3;
    char *S      = "---";
    char *target = "", *ans = licenseKeyFormatting(S, K);
    ck_assert_str_eq(ans, target);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}