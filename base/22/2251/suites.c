/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/9/28 19:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2251.c"

START_TEST(test_official_1) {
    int *flowers[] = { (int[]) { 1, 6 }, (int[]) { 3, 7 }, (int[]) { 9, 12 }, (int[]) { 4, 13 } };
    int len, people[] = { 2, 3, 7, 11 };
    int target[] = { 1, 2, 2, 2 }, *ans = fullBloomFlowers(flowers, LEN(flowers), NULL, people, LEN(people), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int *flowers[] = { (int[]) { 1, 10 }, (int[]) { 3, 3 } };
    int len, people[] = { 3, 3, 2 };
    int target[] = { 2, 2, 1 }, *ans = fullBloomFlowers(flowers, LEN(flowers), NULL, people, LEN(people), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}