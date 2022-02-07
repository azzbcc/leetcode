/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/2/7 上午11:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1405.c"

START_TEST(test_official_1) {
    int a = 1, b = 1, c = 7;
    char *target = "ccaccbcc", *ans = longestDiverseString(a, b, c);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int a = 2, b = 2, c = 1;
    char *target = "ababc", *ans = longestDiverseString(a, b, c);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    int a = 7, b = 1, c = 0;
    char *target = "aabaa", *ans = longestDiverseString(a, b, c);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
//    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}