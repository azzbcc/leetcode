/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/16 下午16:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0943.c"

START_TEST(test_official_1) {
    char *arr[] = { "alex", "loves", "leetcode" };

    char *target = "leetcodelovesalex", *ans = shortestSuperstring(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_str_eq(target, ans);

    free(ans);
}

START_TEST(test_official_2) {
    char *arr[] = { "catg", "ctaagt", "gcta", "ttca", "atgcatc" };

    char *target = "gctaagttcatgcatc", *ans = shortestSuperstring(arr, sizeof(arr) / sizeof(arr[0]));

    ck_assert_str_eq(target, ans);

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}