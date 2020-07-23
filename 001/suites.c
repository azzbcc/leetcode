/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 20-7-23 下午18:56
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <check.h>
#include <stdlib.h>

#include "001.c"

START_TEST(test_official) {
    int arr[] = { 2, 7, 11, 15 }, target = 9, retSize;
    int *ans = twoSum(arr, sizeof(arr) / sizeof(arr[0]), target, &retSize);

    ck_assert_int_eq(retSize, 2);
    ck_assert_msg(ans[0] == 0 && ans[1] == 1, "error, except [0, 1] but got [%d, %d] on twoSum([2, 7, 11, 15], 9).", ans[0], ans[1]);

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}