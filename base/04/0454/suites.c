/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/27 上午11:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0454.c"

START_TEST(test_official) {
    int A[] = { 1, 2 }, B[] = { -2, -1 }, C[] = { -1, 2 }, D[] = { 0, 2 };

    int target = 2, ans = fourSumCount(A, LEN(A), B, LEN(B), C, LEN(C), D, LEN(D));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int A[] = { 0 }, B[] = { 0 }, C[] = { 0 }, D[] = { 0 };

    int target = 1, ans = fourSumCount(A, LEN(A), B, LEN(B), C, LEN(C), D, LEN(D));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int A[] = { 0, 1, -1 }, B[] = { -1, 1, 0 }, C[] = { 0, 0, 1 }, D[] = { -1, 1, 1 };

    int target = 17, ans = fourSumCount(A, LEN(A), B, LEN(B), C, LEN(C), D, LEN(D));

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official);
}