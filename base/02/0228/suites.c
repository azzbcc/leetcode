/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/10 上午0:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0228.c"

START_TEST(test_official_1) {
    int len, arr[] = { 0, 1, 2, 4, 5, 7 };
    char *target[] = { "0->2", "4->5", "7" };

    char **ans = summaryRanges(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len, arr[] = { 0, 2, 3, 4, 6, 8, 9 };
    char *target[] = { "0", "2->4", "6", "8->9" };

    char **ans = summaryRanges(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_3) {
    int len, arr[] = {};
    char *target[] = {};

    char **ans = summaryRanges(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_4) {
    int len, arr[] = { -1 };
    char *target[] = { "-1" };

    char **ans = summaryRanges(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_5) {
    int len, arr[] = { 0 };
    char *target[] = { "0" };

    char **ans = summaryRanges(arr, LEN(arr), &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}
