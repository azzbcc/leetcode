/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/2/8 下午2:27
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1001.c"

START_TEST(test_official_1) {
    int len, n = 5;
    int *lamps[]   = { (int[]) { 0, 0 }, (int[]) { 4, 4 } };
    int *queries[] = { (int[]) { 1, 1 }, (int[]) { 1, 0 } };
    int target[] = { 1, 0 }, *ans = gridIllumination(n, lamps, LEN(lamps), NULL, queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int len, n = 5;
    int *lamps[]   = { (int[]) { 0, 0 }, (int[]) { 4, 4 } };
    int *queries[] = { (int[]) { 1, 1 }, (int[]) { 1, 1 } };
    int target[] = { 1, 1 }, *ans = gridIllumination(n, lamps, LEN(lamps), NULL, queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int len, n = 5;
    int *lamps[]   = { (int[]) { 0, 0 }, (int[]) { 0, 4 } };
    int *queries[] = { (int[]) { 0, 4 }, (int[]) { 0, 1 }, (int[]) { 1, 4 } };
    int target[] = { 1, 1, 0 }, *ans = gridIllumination(n, lamps, LEN(lamps), NULL, queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int len, n = 6;
    int *lamps[]   = { (int[]) { 2, 5 }, (int[]) { 4, 2 }, (int[]) { 0, 3 }, (int[]) { 0, 5 },
                     (int[]) { 1, 4 }, (int[]) { 4, 2 }, (int[]) { 3, 3 }, (int[]) { 1, 0 } };
    int *queries[] = { (int[]) { 4, 3 }, (int[]) { 3, 1 }, (int[]) { 5, 3 },
                       (int[]) { 0, 5 }, (int[]) { 4, 4 }, (int[]) { 3, 3 } };
    int target[]   = { 1, 0, 1, 1, 0, 1 };
    int *ans       = gridIllumination(n, lamps, LEN(lamps), NULL, queries, LEN(queries), NULL, &len);
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