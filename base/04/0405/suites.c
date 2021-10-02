/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/2 上午2:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0405.c"

START_TEST(test_official_1) {
    int num      = 26;
    char *target = "1a", *ans = toHex(num);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int num      = -1;
    char *target = "ffffffff", *ans = toHex(num);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}