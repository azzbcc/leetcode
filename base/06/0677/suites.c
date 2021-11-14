/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/14 下午8:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0677.c"

START_TEST(test_official) {
    MapSum *sum = mapSumCreate();
    ck_assert_ptr_nonnull(sum);

    mapSumInsert(sum, "apple", 3);
    ck_assert_int_eq(mapSumSum(sum, "ap"), 3);
    mapSumInsert(sum, "app", 2);
    ck_assert_int_eq(mapSumSum(sum, "ap"), 5);
    mapSumInsert(sum, "app", 1);
    ck_assert_int_eq(mapSumSum(sum, "ap"), 4);
    ck_assert_int_eq(mapSumSum(sum, "appp"), 0);

    mapSumFree(sum);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}