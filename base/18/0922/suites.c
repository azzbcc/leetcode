/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/12 上午11:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0922.c"

START_TEST(test_official) {
    int arr[]    = { 4, 2, 5, 7 };
    int target[] = { 4, 5, 2, 7 };

    int len, *ans = sortArrayByParityII(arr, LEN(arr), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}