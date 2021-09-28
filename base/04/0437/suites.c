/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/28 上午10:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0437.c"

START_TEST(test_official_1) {
    int root[] = { 10, 5, -3, 3, 2, null, 11, 3, -2, null, 1 }, targetSum = 18;
    tree_t t = tree_create(root);

    int target = 3, ans = pathSum(t, targetSum);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_official_2) {
    int root[] = { 5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1 }, targetSum = 22;
    tree_t t = tree_create(root);

    int target = 3, ans = pathSum(t, targetSum);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_own) {
    int root[] = { -1, 1, 1 }, targetSum = 0;
    tree_t t = tree_create(root);

    int target = 2, ans = pathSum(t, targetSum);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}