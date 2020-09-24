/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/24 上午11:20
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0501.c"

START_TEST(test_official) {
    int len, arr[] = { 1, null, 2, 2 };
    tree_t t = tree_create(arr, sizeof(arr) / sizeof(arr[0]));

    int target[] = { 2 }, *ans = findMode(t, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(ans, target, sizeof(target));

    tree_free(t);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}