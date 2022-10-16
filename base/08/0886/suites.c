/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/16 上午11:00
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0886.c"

START_TEST(test_official_1) {
    int n = 4, *dislikes[] = { (int[]) { 1, 2 }, (int[]) { 1, 3 }, (int[]) { 2, 4 } };
    bool target = true, ans = possibleBipartition(n, dislikes, LEN(dislikes), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int n = 3, *dislikes[] = { (int[]) { 1, 2 }, (int[]) { 1, 3 }, (int[]) { 2, 3 } };
    bool target = false, ans = possibleBipartition(n, dislikes, LEN(dislikes), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int n = 5, *dislikes[] = { (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 3, 4 }, (int[]) { 4, 5 }, (int[]) { 1, 5 } };
    bool target = false, ans = possibleBipartition(n, dislikes, LEN(dislikes), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int n = 5, *dislikes[] = { (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 3, 4 }, (int[]) { 4, 5 }, (int[]) { 1, 5 } };
    bool target = false, ans = possibleBipartition(n, dislikes, LEN(dislikes), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}