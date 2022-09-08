/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/9/8 下午2:10
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0667.c"

START_TEST(test_official_1) {
    int n = 3, k = 1;
    int target[] = { 1, 2, 3 };
    int len, *ans = constructArray(n, k, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int n = 3, k = 2;
    int target[] = { 1, 3, 2 };
    int len, *ans = constructArray(n, k, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int n = 5, k = 4;
    int target[] = { 1, 5, 2, 4, 3 };
    int len, *ans = constructArray(n, k, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}