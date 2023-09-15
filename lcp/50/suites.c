/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/9/15 15:10
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "lcp_50.c"

START_TEST(test_official_1) {
    int gem[]         = { 3, 1, 2 };
    int *operations[] = { (int[]) { 0, 2 }, (int[]) { 2, 1 }, (int[]) { 2, 0 } };
    int target = 2, ans = giveGem(gem, LEN(gem), operations, LEN(operations), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int gem[]         = { 100, 0, 50, 100 };
    int *operations[] = { (int[]) { 0, 2 }, (int[]) { 0, 1 }, (int[]) { 3, 0 }, (int[]) { 3, 0 } };
    int target = 75, ans = giveGem(gem, LEN(gem), operations, LEN(operations), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int gem[]         = { 0, 0, 0, 0 };
    int *operations[] = { (int[]) { 1, 2 }, (int[]) { 3, 1 }, (int[]) { 1, 2 } };
    int target = 0, ans = giveGem(gem, LEN(gem), operations, LEN(operations), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int gem[]         = { 0, 2, 5, 4 };
    int *operations[] = { (int[]) { 3, 2 }, (int[]) { 3, 2 }, (int[]) { 1, 3 }, (int[]) { 0, 2 }, (int[]) { 3, 0 },
                          (int[]) { 3, 1 }, (int[]) { 0, 3 }, (int[]) { 2, 1 }, (int[]) { 3, 0 } };
    int target = 4, ans = giveGem(gem, LEN(gem), operations, LEN(operations), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}