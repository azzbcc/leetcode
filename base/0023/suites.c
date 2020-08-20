/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/10 上午11:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0023.c"

START_TEST(test_official) {
    int arr[][4]     = { { 3, 1, 4, 5 }, { 3, 1, 3, 4 }, { 2, 2, 6 } };
    int arr_target[] = { 1, 1, 2, 3, 4, 4, 5, 6 };

    list_t lists[3] = { NULL };
    for (int i = 0; i < sizeof(lists) / sizeof(lists[0]); ++i) {
        lists[i] = list_create(arr[i] + 1, arr[i][0]);
    }
    list_t target = list_create(arr_target, sizeof(arr_target) / sizeof(arr_target[0]));
    list_t ans    = mergeKLists(lists, sizeof(lists) / sizeof(lists[0]));

    fail_if(!list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}