/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/15 上午11:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1042.c"

START_TEST(test_official_1) {
    int n = 3, *paths[] = { (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 3, 1 } };
    int target[] = { 1, 2, 3 };
    int len, *ans = gardenNoAdj(n, paths, LEN(paths), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int n = 4, *paths[] = { (int[]) { 1, 2 }, (int[]) { 3, 4 } };
    int target[] = { 1, 2, 1, 2 };
    int len, *ans = gardenNoAdj(n, paths, LEN(paths), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int n = 4, *paths[] = { (int[]) { 1, 2 }, (int[]) { 2, 3 }, (int[]) { 3, 4 },
                            (int[]) { 4, 1 }, (int[]) { 1, 3 }, (int[]) { 2, 4 } };
    int target[] = { 1, 2, 3, 4 };
    int len, *ans = gardenNoAdj(n, paths, LEN(paths), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int n = 1, *paths[] = {};
    int target[] = { 1 };
    int len, *ans = gardenNoAdj(n, paths, LEN(paths), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}