/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/3/21 下午8:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2389.c"

START_TEST(test_official_1) {
    int nums[] = { 4, 5, 2, 1 }, queries[] = { 3, 10, 21 };
    int target[] = { 2, 3, 4 }, len, *ans = answerQueries(nums, LEN(nums), queries, LEN(queries), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int nums[] = { 2, 3, 4, 5 }, queries[] = { 1 };
    int target[] = { 0 }, len, *ans = answerQueries(nums, LEN(nums), queries, LEN(queries), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}