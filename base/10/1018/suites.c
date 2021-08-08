/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/14 上午11:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1018.c"

START_TEST(test_official_1) {
    int len, arr[] = { 0, 1, 1 };
    bool target[] = { true, false, false }, *ans = prefixesDivBy5(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int len, arr[] = { 1, 1, 1 };
    bool target[] = { false, false, false }, *ans = prefixesDivBy5(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_3) {
    int len, arr[] = { 0, 1, 1, 1, 1, 1 };
    bool target[] = { true, false, false, false, true, false }, *ans = prefixesDivBy5(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_4) {
    int len, arr[] = { 1, 1, 1, 0, 1 };
    bool target[] = { false, false, false, false, false }, *ans = prefixesDivBy5(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}