/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/23 10:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2678.c"

START_TEST(test_official_1) {
    char *details[] = { "7868190130M7522", "5303914400F9211", "9273338290F4010" };
    int target = 2, ans = countSeniors(details, LEN(details));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *details[] = { "1313579440F2036", "2921522980M5644" };
    int target = 0, ans = countSeniors(details, LEN(details));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}