/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/8/9 11:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1281.c"

START_TEST(test_official_1) {
    int n      = 234;
    int target = 15, ans = subtractProductAndSum(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 4421;
    int target = 21, ans = subtractProductAndSum(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}