/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/13 22:27
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1488.c"

START_TEST(test_official_1) {
    int rains[]  = { 1, 2, 3, 4 };
    int target[] = { -1, -1, -1, -1 };
    int len, *ans = avoidFlood(rains, LEN(rains), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int rains[]  = { 1, 2, 0, 0, 2, 1 };
    int target[] = { -1, -1, 2, 1, -1, -1 };
    int len, *ans = avoidFlood(rains, LEN(rains), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int rains[]  = { 1, 2, 0, 1, 2 };
    int target[] = {};
    int len, *ans = avoidFlood(rains, LEN(rains), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int rains[]  = { 69, 0, 0, 0, 69 };
    int target[] = { -1, 69, 5, 5, -1 };
    int len, *ans = avoidFlood(rains, LEN(rains), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}