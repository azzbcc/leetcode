/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/9/3 上午11:48
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0646.c"

START_TEST(test_official) {
    int *pairs[] = { (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 3, 4 } };
    int target = 2, ans = findLongestChain(pairs, LEN(pairs), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int *pairs[] = { (int[]) { -10, -8 }, (int[]) { 8, 9 }, (int[]) { -5, 0 }, (int[]) { 6, 10 },
                     (int[]) { -6, -4 },  (int[]) { 1, 7 }, (int[]) { 9, 10 }, (int[]) { -4, 7 } };
    int target = 4, ans = findLongestChain(pairs, LEN(pairs), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}