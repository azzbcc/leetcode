/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/7 上午0:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "0093.c"

int comp(const void *a, const void *b) {
    return strcmp(*( char ** )a, *( char ** )b);
}

START_TEST(test_official) {
    int len;
    char *arr = "25525511135", *target[] = { "255.255.11.135", "255.255.111.35" };
    char **ans = restoreIpAddresses(arr, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));

    qsort(ans, len, sizeof(ans[0]), comp);
    qsort(target, len, sizeof(target[0]), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

START_TEST(test_failed) {
    int len;
    char *arr = "010010", *target[] = { "0.10.0.10","0.100.1.0" };
    char **ans = restoreIpAddresses(arr, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));

    qsort(ans, len, sizeof(ans[0]), comp);
    qsort(target, len, sizeof(target[0]), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
        free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}