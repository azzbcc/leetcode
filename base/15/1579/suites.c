/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/27 下午1:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1579.c"

START_TEST(test_official_1) {
    int n = 4, *edges[] = { (int[]) { 3, 1, 2 }, (int[]) { 3, 2, 3 }, (int[]) { 1, 1, 3 },
                            (int[]) { 1, 2, 4 }, (int[]) { 1, 1, 2 }, (int[]) { 2, 3, 4 } };
    int target = 2, ans = maxNumEdgesToRemove(n, edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 4, *edges[] = { (int[]) { 3, 1, 2 }, (int[]) { 3, 2, 3 }, (int[]) { 1, 1, 4 }, (int[]) { 2, 1, 4 } };
    int target = 0, ans = maxNumEdgesToRemove(n, edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n = 4, *edges[] = { (int[]) { 3, 2, 3 }, (int[]) { 1, 1, 2 }, (int[]) { 2, 3, 4 } };
    int target = -1, ans = maxNumEdgesToRemove(n, edges, LEN(edges), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}