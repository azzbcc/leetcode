/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/26 下午2:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1759.c"

START_TEST(test_official_1) {
    char *s    = "abbcccaa";
    int target = 13, ans = countHomogenous(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s    = "xy";
    int target = 2, ans = countHomogenous(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s    = "zzzzz";
    int target = 15, ans = countHomogenous(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}