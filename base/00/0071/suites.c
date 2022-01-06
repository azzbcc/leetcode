/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/6 上午11:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0071.c"

START_TEST(test_official_1) {
    char path[]  = "/home/";
    char *target = "/home", *ans = simplifyPath(path);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char path[]  = "/../";
    char *target = "/", *ans = simplifyPath(path);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_3) {
    char path[]  = "/home//foo/";
    char *target = "/home/foo", *ans = simplifyPath(path);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_4) {
    char path[]  = "/a/./b/../../c/";
    char *target = "/c", *ans = simplifyPath(path);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed_1) {
    char path[]  = "/a//b////c/d//././/..";
    char *target = "/a/b/c", *ans = simplifyPath(path);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_own_1) {
    char path[]  = "/a//b////c/d//././/.";
    char *target = "/a/b/c/d", *ans = simplifyPath(path);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_own_2) {
    char path[]  = "/a//b////c/d//././/a";
    char *target = "/a/b/c/d/a", *ans = simplifyPath(path);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_own_3) {
    char path[]  = "/.";
    char *target = "/", *ans = simplifyPath(path);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed_2) {
    char path[]  = "/...";
    char *target = "/...", *ans = simplifyPath(path);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_failed_3) {
    char path[]  = "/.hidden";
    char *target = "/.hidden", *ans = simplifyPath(path);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_3);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_own_1);
    tcase_add_test(t, test_own_2);
    tcase_add_test(t, test_own_3);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}