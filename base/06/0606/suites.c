/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/2 下午5:39
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0606.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3, 4 };
    tree_t t  = tree_create(arr);

    char *target = "1(2(4))(3)", *ans = tree2str(t);
    ck_assert_str_eq(ans, target);

    tree_free(t);
}

START_TEST(test_official_2) {
    int arr[] = { 1,2,3,null,4 };
    tree_t t  = tree_create(arr);

    char *target = "1(2()(4))(3)", *ans = tree2str(t);
    ck_assert_str_eq(ans, target);

    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}