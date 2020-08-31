/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/10 下午3:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0024.c"

START_TEST(test_official) {
    int arr[]        = { 1, 2, 3, 4 };
    int arr_target[] = { 2, 1, 4, 3 };

    list_t l      = list_create(arr, sizeof(arr) / sizeof(arr[0]));
    list_t target = list_create(arr_target, sizeof(arr_target) / sizeof(arr_target[0]));
    list_t ans    = swapPairs(l);

    fail_if(!list_equal(target, ans));

    list_free(target);
    list_free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}