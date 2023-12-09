/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/12/9 21:33
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2048.c"

START_TEST(test_official_1) {
    int n      = 1;
    int target = 22, ans = nextBeautifulNumber(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n      = 1000;
    int target = 1333, ans = nextBeautifulNumber(n);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n      = 3000;
    int target = 3133, ans = nextBeautifulNumber(n);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}