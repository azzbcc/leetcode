/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/3/11 09:00
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2129.c"

START_TEST(test_official_1) {
    char title[] = "capiTalIze tHe titLe";
    char *target = "Capitalize The Title";
    char *ans    = capitalizeTitle(title);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char title[] = "First leTTeR of EACH Word";
    char *target = "First Letter of Each Word";
    char *ans    = capitalizeTitle(title);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    char title[] = "i lOve leetcode";
    char *target = "i Love Leetcode";
    char *ans    = capitalizeTitle(title);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}