/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/13 下午5:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0079.c"

START_TEST(test_official_1) {
    char *arr[] = { "ABCE", "SFCS", "ADEE" }, *word = "ABCCED";
    int len = strlen(arr[0]);

    bool target = true, ans = exist(arr, sizeof(arr) / sizeof(arr[0]), &len, word);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    char *arr[] = { "ABCE", "SFCS", "ADEE" }, *word = "SEE";
    int len = strlen(arr[0]);

    bool target = true, ans = exist(arr, sizeof(arr) / sizeof(arr[0]), &len, word);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    char *arr[] = { "ABCE", "SFCS", "ADEE" }, *word = "ABCB";
    int len = strlen(arr[0]);

    bool target = false, ans = exist(arr, sizeof(arr) / sizeof(arr[0]), &len, word);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed_1) {
    char *arr[] = { "a" }, *word = "a";
    int len = strlen(arr[0]);

    bool target = true, ans = exist(arr, sizeof(arr) / sizeof(arr[0]), &len, word);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed_2) {
    char *arr[] = { "ABCE", "SFES", "ADEE" }, *word = "ABCESEEEFS";
    int len = strlen(arr[0]);

    bool target = true, ans = exist(arr, sizeof(arr) / sizeof(arr[0]), &len, word);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}