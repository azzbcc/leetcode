/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/6/19 上午10:14
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0508.c"

START_TEST(test_official_1) {
    int arr[]    = { 5, 2, -3 };
    int target[] = { 2, -3, 4 };
    tree_t t     = tree_create(arr);
    int len, *ans = findFrequentTreeSum(t, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[]    = { 5, 2, -5 };
    int target[] = { 2 };
    tree_t t     = tree_create(arr);
    int len, *ans = findFrequentTreeSum(t, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}