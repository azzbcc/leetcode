/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/1/6 14:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "2807.c"

START_TEST(test_official_1) {
    int arr[] = { 18, 6, 10, 3 }, t[] = { 18, 6, 6, 2, 10, 1, 3 };
    list_t l = list_create(arr), target = list_create(t);
    list_t ans = insertGreatestCommonDivisors(l);

    ck_assert(list_equal(ans, target));
    list_free(ans);
    list_free(target);
}

START_TEST(test_official_2) {
    int arr[] = { 7 }, t[] = { 7 };
    list_t l = list_create(arr), target = list_create(t);
    list_t ans = insertGreatestCommonDivisors(l);

    ck_assert(list_equal(ans, target));
    list_free(ans);
    list_free(target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}