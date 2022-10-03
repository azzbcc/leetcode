/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/7 上午10:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0636.c"

START_TEST(test_official_1) {
    int len, n = 2;
    char *logs[] = { "0:start:0", "1:start:2", "1:end:5", "0:end:6" };
    int target[] = { 3, 4 };
    int *ans     = exclusiveTime(n, logs, LEN(logs), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int len, n = 1;
    char *logs[] = { "0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7" };
    int target[] = { 8 };
    int *ans     = exclusiveTime(n, logs, LEN(logs), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int len, n = 2;
    char *logs[] = { "0:start:0", "0:start:2", "0:end:5", "1:start:6", "1:end:6", "0:end:7" };
    int target[] = { 7, 1 };
    int *ans     = exclusiveTime(n, logs, LEN(logs), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_4) {
    int len, n = 2;
    char *logs[] = { "0:start:0", "0:start:2", "0:end:5", "1:start:7", "1:end:7", "0:end:8" };
    int target[] = { 8, 1 };
    int *ans     = exclusiveTime(n, logs, LEN(logs), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_5) {
    int len, n = 1;
    char *logs[] = { "0:start:0", "0:end:0" };
    int target[] = { 1 };
    int *ans     = exclusiveTime(n, logs, LEN(logs), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
    tcase_add_test(t, test_official_5);
}