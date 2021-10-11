/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/11 上午11:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0273.c"

START_TEST(test_official_1) {
    int num      = 123;
    char *target = "One Hundred Twenty Three";
    char *ans    = numberToWords(num);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    int num      = 12345;
    char *target = "Twelve Thousand Three Hundred Forty Five";
    char *ans    = numberToWords(num);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    int num      = 1234567;
    char *target = "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven";
    char *ans    = numberToWords(num);

    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_4) {
    int num      = 1234567891;
    char *target = "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One";
    char *ans    = numberToWords(num);

    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}