/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/20 10:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2788.c"

START_TEST(test_official_1) {
    int len;
    char separator = '.';
    char *t[100], words[][21] = { "one.two.three", "four.five", "six" };
    char *target[] = { "one", "two", "three", "four", "five", "six" };
    for (int i = 0; i < LEN(words); t[i] = words[i], ++i) {}
    char **ans = splitWordsBySeparator(t, LEN(words), separator, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char separator = '$';
    char *t[100], words[][21] = { "$easy$", "$problem$" };
    char *target[] = { "easy", "problem" };
    for (int i = 0; i < LEN(words); t[i] = words[i], ++i) {}
    char **ans = splitWordsBySeparator(t, LEN(words), separator, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_3) {
    int len;
    char separator = '|';
    char *t[100], words[][21] = { "|||" };
    char *target[] = {};
    for (int i = 0; i < LEN(words); t[i] = words[i], ++i) {}
    char **ans = splitWordsBySeparator(t, LEN(words), separator, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}