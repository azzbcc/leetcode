/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/18 15:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2007.c"

START_TEST(test_official_1) {
    int len, changed[] = { 1, 3, 4, 2, 6, 8 };
    int target[] = { 1, 3, 4 }, *ans = findOriginalArray(changed, LEN(changed), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int len, changed[] = { 6, 3, 0, 1 };
    int target[] = {}, *ans = findOriginalArray(changed, LEN(changed), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int len, changed[] = { 1 };
    int target[] = {}, *ans = findOriginalArray(changed, LEN(changed), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int len, changed[] = { 0, 0, 0, 0 };
    int target[] = { 0, 0 }, *ans = findOriginalArray(changed, LEN(changed), &len);
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