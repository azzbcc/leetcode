/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/27 下午2:51
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0938.c"

START_TEST(test_official_1) {
    int low = 7, high = 15;
    int arr[]  = { 10, 5, 15, 3, 7, null, 18 };
    tree_t tt  = tree_create(arr);
    int target = 32, ans = rangeSumBST(tt, low, high);
    ck_assert_int_eq(ans, target);
    tree_free(tt);
}

START_TEST(test_official_2) {
    int low = 6, high = 10;
    int arr[]  = { 10,5,15,3,7,13,18,1,null,6 };
    tree_t tt  = tree_create(arr);
    int target = 23, ans = rangeSumBST(tt, low, high);
    ck_assert_int_eq(ans, target);
    tree_free(tt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}