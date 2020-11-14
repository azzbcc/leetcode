/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/14 下午1:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1122.c"

START_TEST(test_official) {
    int arr1[] = { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 }, arr2[] = { 2, 1, 4, 3, 9, 6 };
    int target[] = { 2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19 };

    int len, *ans = relativeSortArray(arr1, LEN(arr1), arr2, LEN(arr2), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}