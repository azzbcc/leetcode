/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/18 上午11:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0092.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2, 3, 4, 5 };
    int trr[] = { 1, 4, 3, 2, 5 };
    int left = 2, right = 4;
    list_t head   = list_create(arr);
    list_t target = list_create(trr);

    list_t ans = reverseBetween(head, left, right);
    ck_assert(list_equal(ans, target));

    list_free(ans);
    list_free(target);
}

START_TEST(test_official_2) {
    int arr[] = { 5 };
    int trr[] = { 5 };
    int left = 1, right = 1;
    list_t head   = list_create(arr);
    list_t target = list_create(trr);

    list_t ans = reverseBetween(head, left, right);
    ck_assert(list_equal(ans, target));

    list_free(ans);
    list_free(target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}