/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/1 上午12:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0303.c"

START_TEST(test_official) {
    int arr[] = { -2, 0, 3, -5, 2, -1 };

    NumArray *array = numArrayCreate(arr, LEN(arr));
    ck_assert_ptr_nonnull(array);
    ck_assert_int_eq(1, numArraySumRange(array, 0, 2));
    ck_assert_int_eq(-1, numArraySumRange(array, 2, 5));
    ck_assert_int_eq(-3, numArraySumRange(array, 0, 5));
    numArrayFree(array);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}