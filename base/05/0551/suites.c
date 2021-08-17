/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/8/17 下午5:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0551.c"

START_TEST(test_official_1) {
    char *s     = "PPALLP";
    bool target = true, ans = checkRecord(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s     = "PPALLL";
    bool target = false, ans = checkRecord(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}