/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/1 上午10:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0165.c"

START_TEST(test_official_1) {
    char *version1 = "1.01", *version2 = "1.001";
    int target = 0, ans = compareVersion(version1, version2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *version1 = "1.0", *version2 = "1.0.0";
    int target = 0, ans = compareVersion(version1, version2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    char *version1 = "0.1", *version2 = "1.1";
    int target = -1, ans = compareVersion(version1, version2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    char *version1 = "1.0.1", *version2 = "1";
    int target = 1, ans = compareVersion(version1, version2);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_5) {
    char *version1 = "7.5.2.4", *version2 = "7.5.3";
    int target = -1, ans = compareVersion(version1, version2);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}