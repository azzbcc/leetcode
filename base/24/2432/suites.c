/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/5/5 14:40
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2432.c"

START_TEST(test_official_1) {
    int n = 10, *logs[] = { (int[]) { 0, 3 }, (int[]) { 2, 5 }, (int[]) { 0, 9 }, (int[]) { 1, 15 } };
    int target = 1, ans = hardestWorker(n, logs, LEN(logs), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 26, *logs[] = { (int[]) { 1, 1 }, (int[]) { 3, 7 }, (int[]) { 2, 12 }, (int[]) { 7, 17 } };
    int target = 3, ans = hardestWorker(n, logs, LEN(logs), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n = 10, *logs[] = { (int[]) { 0, 10 }, (int[]) { 1, 20 } };
    int target = 0, ans = hardestWorker(n, logs, LEN(logs), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}