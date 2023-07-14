/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/14 18:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <tree.h>

#include "0979.c"

START_TEST(test_official_1) {
    int nums[] = { 3, 0, 0 };
    tree_t t   = tree_create(nums);

    int target = 2, ans = distributeCoins(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_official_2) {
    int nums[] = { 0, 3, 0 };
    tree_t t   = tree_create(nums);

    int target = 3, ans = distributeCoins(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_official_3) {
    int nums[] = { 1, 0, 2 };
    tree_t t   = tree_create(nums);

    int target = 2, ans = distributeCoins(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

START_TEST(test_official_4) {
    int nums[] = { 1, 0, 0, null, 3 };
    tree_t t   = tree_create(nums);

    int target = 4, ans = distributeCoins(t);
    ck_assert_int_eq(ans, target);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}