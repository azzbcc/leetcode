/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/8 下午12:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>
#include <tree.h>

#include "04_03.c"

START_TEST(test_official) {
    int len, arr[] = { 1, 2, 3, 4, 5, null, 7, 8 };
    int cols[]      = { 1, 2, 3, 1 };
    int target[][3] = { { 1 }, { 2, 3 }, { 4, 5, 7 }, { 8 } };

    tree_t t    = tree_create(arr, sizeof(arr) / sizeof(arr[0]));
    list_t *ans = listOfDepth(t, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        list_t l = list_create_size(target[i], cols[i]);

        fail_if(!list_equal(l, ans[i]));

        list_free(l);
        list_free(ans[i]);
    }
    free(ans);
    tree_free(t);
}

START_TEST(test_failed) {
    int len, arr[] = { 5 };
    int cols[]      = { 1 };
    int target[][1] = { { 5 } };

    tree_t t    = tree_create(arr, sizeof(arr) / sizeof(arr[0]));
    list_t *ans = listOfDepth(t, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        list_t l = list_create_size(target[i], cols[i]);

        fail_if(!list_equal(l, ans[i]));

        list_free(l);
        list_free(ans[i]);
    }
    free(ans);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}