/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/21 下午6:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1415.c"

START_TEST(test_official_1) {
    int n = 1, k = 3;
    char *target = "c", *ans = getHappyString(n, k);

    ck_assert_str_eq(target, ans);
}
START_TEST(test_official_2) {
    int n = 1, k = 4;
    char *target = "", *ans = getHappyString(n, k);

    ck_assert_str_eq(target, ans);
}
START_TEST(test_official_3) {
    int n = 3, k = 9;
    char *target = "cab", *ans = getHappyString(n, k);

    ck_assert_str_eq(target, ans);
}
START_TEST(test_official_4) {
    int n = 2, k = 7;
    char *target = "", *ans = getHappyString(n, k);

    ck_assert_str_eq(target, ans);
}
START_TEST(test_official_5) {
    int n = 10, k = 100;
    char *target = "abacbabacb", *ans = getHappyString(n, k);

    ck_assert_str_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}