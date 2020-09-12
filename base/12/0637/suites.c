/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/12 下午1:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0637.c"

START_TEST(test_official) {
    int len, arr[] = { 3, 9, 20, null, null, 15, 7 };
    tree_t t = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));

    double target[] = {3, 14.5, 11}, *ans = averageOfLevels(t, &len);

    ck_assert_int_eq(len, sizeof(target)/sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        ck_assert_double_eq(ans[i], target[i]);
    }

    tree_free(t);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}