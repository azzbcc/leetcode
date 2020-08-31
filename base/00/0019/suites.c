/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/7 下午6:38
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0019.c"

START_TEST(test_official) {
    int input = 2, arr1[] = { 1, 2, 3, 4, 5 }, arr2[] = { 1, 2, 3, 5 };
    list_t l1 = list_create(arr1, sizeof(arr1) / sizeof(arr1[0]));
    list_t l2 = list_create(arr2, sizeof(arr2) / sizeof(arr2[0]));

    list_t l3 = removeNthFromEnd(l1, input);

    fail_if(!list_equal(l2, l3));

    list_free(l2);
    list_free(l3);
}

START_TEST(test_failed) {
    int input = 1, arr1[] = { 1 }, arr2[] = {};
    list_t l1 = list_create(arr1, sizeof(arr1) / sizeof(arr1[0]));
    list_t l2 = list_create(arr2, sizeof(arr2) / sizeof(arr2[0]));

    list_t l3 = removeNthFromEnd(l1, input);

    fail_if(!list_equal(l2, l3));

    list_free(l2);
    list_free(l3);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}