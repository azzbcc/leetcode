/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/2/16 上午11:09
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1719.c"

START_TEST(test_official_1) {
    int *pairs[] = { (int[]) { 1, 2 }, (int[]) { 2, 3 } };
    int target = 1, ans = checkWays(pairs, LEN(pairs), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *pairs[] = { (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 1, 3 } };
    int target = 2, ans = checkWays(pairs, LEN(pairs), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *pairs[] = { (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 2, 4 }, (int[]) { 1, 5 } };
    int target = 0, ans = checkWays(pairs, LEN(pairs), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int *pairs[] = { (int[]) { 3, 5 }, (int[]) { 1, 5 }, (int[]) { 1, 2 },
                     (int[]) { 2, 4 }, (int[]) { 2, 5 }, (int[]) { 4, 5 } };
    int target = 1, ans = checkWays(pairs, LEN(pairs), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int *pairs[] = { (int[]) { 1, 5 }, (int[]) { 1, 3 }, (int[]) { 2, 3 },
                     (int[]) { 2, 4 }, (int[]) { 3, 5 }, (int[]) { 3, 4 } };
    int target = 2, ans = checkWays(pairs, LEN(pairs), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}