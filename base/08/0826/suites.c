/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/5/17 14:35
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0826.c"

START_TEST(test_official_1) {
    int difficulty[] = { 2, 4, 6, 8, 10 }, profit[] = { 10, 20, 30, 40, 50 }, worker[] = { 4, 5, 6, 7 };
    int target = 100, ans = maxProfitAssignment(difficulty, LEN(difficulty), profit, LEN(profit), worker, LEN(worker));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int difficulty[] = { 85, 47, 57 }, profit[] = { 24, 66, 99 }, worker[] = { 40, 25, 25 };
    int target = 0, ans = maxProfitAssignment(difficulty, LEN(difficulty), profit, LEN(profit), worker, LEN(worker));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int difficulty[] = { 68, 35, 52, 47, 86 }, profit[] = { 67, 17, 1, 81, 3 }, worker[] = { 92, 10, 85, 84, 82 };
    int target = 324, ans = maxProfitAssignment(difficulty, LEN(difficulty), profit, LEN(profit), worker, LEN(worker));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}