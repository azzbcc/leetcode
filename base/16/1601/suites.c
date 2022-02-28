/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/2/28 下午2:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1601.c"

START_TEST(test_official_1) {
    int n = 5, *requests[] = { (int[]) { 0, 1 }, (int[]) { 1, 0 }, (int[]) { 0, 1 },
                               (int[]) { 1, 2 }, (int[]) { 2, 0 }, (int[]) { 3, 4 } };
    int target = 5, ans = maximumRequests(n, requests, LEN(requests), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 3, *requests[] = { (int[]) { 0, 0 }, (int[]) { 1, 2 }, (int[]) { 2, 1 } };
    int target = 3, ans = maximumRequests(n, requests, LEN(requests), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n = 4, *requests[] = { (int[]) { 0, 3 }, (int[]) { 3, 1 }, (int[]) { 1, 2 }, (int[]) { 2, 0 } };
    int target = 4, ans = maximumRequests(n, requests, LEN(requests), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}