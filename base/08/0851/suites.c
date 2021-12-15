/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/12/15 上午10:21
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0851.c"

START_TEST(test_official_1) {
    int *richer[] = { (int[]) { 1, 0 }, (int[]) { 2, 1 }, (int[]) { 3, 1 }, (int[]) { 3, 7 },
                      (int[]) { 4, 3 }, (int[]) { 5, 3 }, (int[]) { 6, 3 } };
    int quiet[]   = { 3, 2, 5, 4, 6, 1, 7, 0 };
    int target[]  = { 5, 5, 2, 5, 4, 5, 6, 7 };
    int len, *ans = loudAndRich(richer, LEN(richer), NULL, quiet, LEN(quiet), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int *richer[] = {};
    int quiet[]   = { 0 };
    int target[]  = { 0 };
    int len, *ans = loudAndRich(richer, LEN(richer), NULL, quiet, LEN(quiet), &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}