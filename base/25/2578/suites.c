/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/9 08:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2578.c"

START_TEST(test_official_1) {
    int num    = 4325;
    int target = 59, ans = splitNum(num);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int num    = 687;
    int target = 75, ans = splitNum(num);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}