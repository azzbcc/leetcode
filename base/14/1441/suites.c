/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/15 下午7:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1441.c"

START_TEST(test_official_1) {
    int len, arr[] = { 1, 3 }, n = 3;
    char *target[] = { "Push", "Push", "Pop", "Push" };
    char **ans     = buildArray(arr, LEN(arr), n, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len, arr[] = { 1, 2, 3 }, n = 3;
    char *target[] = { "Push", "Push", "Push" };
    char **ans     = buildArray(arr, LEN(arr), n, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_3) {
    int len, arr[] = { 1, 2 }, n = 4;
    char *target[] = { "Push", "Push" };
    char **ans     = buildArray(arr, LEN(arr), n, &len);
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