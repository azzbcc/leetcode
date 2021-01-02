/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/3 上午2:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0086.c"

START_TEST(test_official) {
    int arr[] = { 1, 4, 3, 2, 5, 2 }, x = 3;
    int target[] = { 1, 2, 2, 4, 3, 5 };

    list_t la = list_create(arr), lt = list_create(target);

    list_t ans = partition(la, x);
    ck_assert(list_equal(ans, lt));

    list_free(ans);
    list_free(lt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}