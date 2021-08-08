/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/15 上午10:41
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0485.c"

START_TEST(test_official) {
    int arr[]  = { 1, 1, 0, 1, 1, 1 };
    int target = 3, ans = findMaxConsecutiveOnes(arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}
