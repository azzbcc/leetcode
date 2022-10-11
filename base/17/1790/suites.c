/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/11 上午11:29
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1790.c"

START_TEST(test_official_1) {
    char *s1 = "bank", *s2 = "kanb";
    ck_assert_int_eq(true, areAlmostEqual(s1, s2));
}

START_TEST(test_official_2) {
    char *s1 = "attack", *s2 = "defend";
    ck_assert_int_eq(false, areAlmostEqual(s1, s2));
}

START_TEST(test_official_3) {
    char *s1 = "kelb", *s2 = "kelb";
    ck_assert_int_eq(true, areAlmostEqual(s1, s2));
}

START_TEST(test_official_4) {
    char *s1 = "abcd", *s2 = "dcba";
    ck_assert_int_eq(false, areAlmostEqual(s1, s2));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}