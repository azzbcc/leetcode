/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/24 11:41
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "2385.c"

START_TEST(test_official_1) {
    int nums[] = { 1, 5, 3, null, 4, 10, 6, 9, 2 }, start = 3;
    tree_t root = tree_create(nums);

    int target = 4, ans = amountOfTime(root, start);
    ck_assert_int_eq(ans, target);

    tree_free(root);
}

START_TEST(test_official_2) {
    int nums[] = { 1 }, start = 1;
    tree_t root = tree_create(nums);

    int target = 0, ans = amountOfTime(root, start);
    ck_assert_int_eq(ans, target);

    tree_free(root);
}

START_TEST(test_own) {
    int nums[] = { 1, 2 }, start = 1;
    tree_t root = tree_create(nums);

    int target = 1, ans = amountOfTime(root, start);
    ck_assert_int_eq(ans, target);

    tree_free(root);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}