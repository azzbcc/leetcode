/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/22 下午4:03
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0834.c"

START_TEST(test_official) {
    int N = 6, *edges[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 }, (int[]) { 2, 3 }, (int[]) { 2, 4 }, (int[]) { 2, 5 } };
    int target[] = { 8, 12, 6, 10, 10, 10 };
    int len, *ans = sumOfDistancesInTree(N, edges, LEN(edges), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}