/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/23 上午11:50
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0234.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 2 };
    list_t l  = list_create(arr);

    bool target = false, ans = isPalindrome(l);
    ck_assert_int_eq(target, ans);

    list_free(l);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 2, 2, 1 };
    list_t l  = list_create(arr);

    bool target = true, ans = isPalindrome(l);
    ck_assert_int_eq(target, ans);

    list_free(l);
}

START_TEST(test_limit) {
    int arr[] = {};
    list_t l  = list_create(arr);

    bool target = true, ans = isPalindrome(l);
    ck_assert_int_eq(target, ans);

    list_free(l);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}