/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/9 上午9:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0764.c"

START_TEST(test_official_1) {
    int n = 5, *mines[] = { (int[]) { 4, 2 } };
    int target = 2, ans = orderOfLargestPlusSign(n, mines, LEN(mines), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 1, *mines[] = { (int[]) { 0, 0 } };
    int target = 0, ans = orderOfLargestPlusSign(n, mines, LEN(mines), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}