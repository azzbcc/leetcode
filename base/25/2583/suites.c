/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/2/23 00:42
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "2583.c"

START_TEST(test_official_1) {
    int arr[] = { 5, 8, 9, 2, 1, 3, 7, 4, 6 }, k = 2;
    tree_t t = tree_create(arr);

    long long target = 13, ans = kthLargestLevelSum(t, k);
    ck_assert_int_eq(ans, target);
    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 2, null, 3 }, k = 1;
    tree_t t = tree_create(arr);

    long long target = 3, ans = kthLargestLevelSum(t, k);
    ck_assert_int_eq(ans, target);
    tree_free(t);
}

START_TEST(test_failed) {
    int arr[] = { 411310, 211244, 111674 }, k = 2;
    tree_t t = tree_create(arr);

    long long target = 322918, ans = kthLargestLevelSum(t, k);
    ck_assert_int_eq(ans, target);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}