/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/6 上午10:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1653.c"

START_TEST(test_official_1) {
    char *s = "aababbab";
    int target = 2, ans = minimumDeletions(s);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s = "bbaaaaabb";
    int target = 2, ans = minimumDeletions(s);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}