/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/11 上午12:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0703.c"

START_TEST(test_official) {
    int nums[] = { 4, 5, 8, 2 }, k = 3;
    KthLargest *obj = kthLargestCreate(k, nums, LEN(nums));

    ck_assert_int_eq(4, kthLargestAdd(obj, 3));
    ck_assert_int_eq(5, kthLargestAdd(obj, 5));
    ck_assert_int_eq(5, kthLargestAdd(obj, 10));
    ck_assert_int_eq(8, kthLargestAdd(obj, 9));
    ck_assert_int_eq(8, kthLargestAdd(obj, 4));

    kthLargestFree(obj);
}

START_TEST(test_failed) {
    int nums[] = { 5, -1 }, k = 3;
    KthLargest *obj = kthLargestCreate(k, nums, LEN(nums));

    ck_assert_int_eq(-1, kthLargestAdd(obj, 2));
    ck_assert_int_eq(1, kthLargestAdd(obj, 1));
    ck_assert_int_eq(1, kthLargestAdd(obj, -1));
    ck_assert_int_eq(2, kthLargestAdd(obj, 3));
    ck_assert_int_eq(3, kthLargestAdd(obj, 4));

    kthLargestFree(obj);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}