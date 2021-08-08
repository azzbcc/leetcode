/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/23 下午5:56
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0895.c"

START_TEST(test_official) {
    int arr[] = { 5, 7, 5, 7, 4, 5 };

    FreqStack *stack = freqStackCreate();
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        freqStackPush(stack, arr[i]);
    }

    ck_assert_int_eq(5, freqStackPop(stack));
    ck_assert_int_eq(7, freqStackPop(stack));
    ck_assert_int_eq(5, freqStackPop(stack));
    ck_assert_int_eq(4, freqStackPop(stack));

    freqStackFree(stack);
}

START_TEST(test_failed) {
    int arr[] = { 4, 0, 9, 3, 4, 2 };

    FreqStack *stack = freqStackCreate();
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        freqStackPush(stack, arr[i]);
    }
    ck_assert_int_eq(4, freqStackPop(stack));
    freqStackPush(stack, 6);
    ck_assert_int_eq(6, freqStackPop(stack));
    freqStackPush(stack, 1);
    ck_assert_int_eq(1, freqStackPop(stack));
    freqStackPush(stack, 1);
    ck_assert_int_eq(1, freqStackPop(stack));
    freqStackPush(stack, 4);
    ck_assert_int_eq(4, freqStackPop(stack));
    ck_assert_int_eq(2, freqStackPop(stack));
    ck_assert_int_eq(3, freqStackPop(stack));
    ck_assert_int_eq(9, freqStackPop(stack));
    ck_assert_int_eq(0, freqStackPop(stack));
    ck_assert_int_eq(4, freqStackPop(stack));

    freqStackFree(stack);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}