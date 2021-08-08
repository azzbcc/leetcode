/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/26 下午12:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1128.c"

START_TEST(test_official) {
    int *arr[] = { (int[]) { 1, 2 }, (int[]) { 2, 1 }, (int[]) { 3, 4 }, (int[]) { 5, 6 } };
    int target = 1, ans = numEquivDominoPairs(arr, LEN(arr), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}