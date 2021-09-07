/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/7 上午10:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1221.c"

START_TEST(test_official_1) {
    char *s    = "RLRRLLRLRL";
    int target = 4, ans = balancedStringSplit(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s    = "RLLLLRRRLR";
    int target = 3, ans = balancedStringSplit(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *s    = "LLLLRRRR";
    int target = 1, ans = balancedStringSplit(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *s    = "RLRRRLLRLL";
    int target = 2, ans = balancedStringSplit(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}