/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/2 上午10:49
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "offer_22.c"

START_TEST(test_official) {
    int k = 2, arr[] = { 1, 2, 3, 4, 5 };
    list_t l = list_create(arr);

    list_t target = list_find(l, 4), ans = getKthFromEnd(l, k);
    ck_assert(list_equal(ans, target));

    list_free(l);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}