/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/1 上午2:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0888.c"

START_TEST(test_official_1) {
    int a[] = { 1, 1 }, b[] = { 2, 2 };
    int target[] = { 1, 2 };
    int len, *ans = fairCandySwap(a, LEN(a), b, LEN(b), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int a[] = { 1, 2 }, b[] = { 2, 3 };
    int target[] = { 1, 2 };
    int len, *ans = fairCandySwap(a, LEN(a), b, LEN(b), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int a[] = { 2 }, b[] = { 1, 3 };
    int target[] = { 2, 3 };
    int len, *ans = fairCandySwap(a, LEN(a), b, LEN(b), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_4) {
    int a[] = { 1, 2, 5 }, b[] = { 2, 4 };
    int target[] = { 5, 4 };
    int len, *ans = fairCandySwap(a, LEN(a), b, LEN(b), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int a[] = { 1, 17, 14, 1, 16 }, b[] = { 26, 11 };
    int target[] = { 17, 11 };
    int len, *ans = fairCandySwap(a, LEN(a), b, LEN(b), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}