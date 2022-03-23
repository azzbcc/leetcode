/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/23 上午10:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0440.c"

START_TEST(test_official_1) {
    int n = 13, k = 2;
    int target = 10, ans = findKthNumber(n, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 1, k = 1;
    int target = 1, ans = findKthNumber(n, k);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int target[] = { 1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 2, 20, 21, 22, 23, 24, 25, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < LEN(target); ++i) {
        ck_assert_int_eq(findKthNumber(LEN(target), i + 1), target[i]);
    }
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}