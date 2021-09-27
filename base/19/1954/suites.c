/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/27 下午2:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <limits.h>

#include "1954.c"

START_TEST(test_official_1) {
    long long neededApples = 1;
    long long target = 8, ans = minimumPerimeter(neededApples);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    long long neededApples = 13;
    long long target = 16, ans = minimumPerimeter(neededApples);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    long long neededApples = 1000000000;
    long long target = 5040, ans = minimumPerimeter(neededApples);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int arr[]    = { 11, 12, 13 };
    int target[] = { 8, 8, 16 };
    for (int i = 0; i < LEN(arr); ++i) {
        long long ans = minimumPerimeter(arr[i]);
        ck_assert_uint_eq(ans, target[i]);
    }
}

START_TEST(test_failed) {
    long long neededApples = 100000000000000;
    long long target = 233920, ans = minimumPerimeter(neededApples);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}