/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/7 下午7:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1040.c"

START_TEST(test_official_1) {
    int stones[] = { 7, 4, 9 };
    int target[] = { 1, 2 };
    int len, *ans = numMovesStonesII(stones, LEN(stones), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int stones[] = { 6, 5, 4, 3, 10 };
    int target[] = { 2, 3 };
    int len, *ans = numMovesStonesII(stones, LEN(stones), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int stones[] = { 100, 101, 104, 102, 103 };
    int target[] = { 0, 0 };
    int len, *ans = numMovesStonesII(stones, LEN(stones), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}