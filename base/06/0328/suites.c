/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/21 下午2:36
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0328.c"

START_TEST(test_official_1) {
    int arr[]    = { 1, 2, 3, 4, 5 };
    int target[] = { 1, 3, 5, 2, 4 };
    list_t la    = list_create(arr, sizeof(arr) / sizeof(arr[0]));
    list_t lt    = list_create(target, sizeof(target) / sizeof(target[0]));

    list_t ans = oddEvenList(la);
    ck_assert(list_equal(ans, lt));

    list_free(ans);
    list_free(lt);
}
START_TEST(test_official_2) {
    int arr[]    = { 2, 1, 3, 5, 6, 4, 7 };
    int target[] = { 2, 3, 6, 7, 1, 5, 4 };
    list_t la    = list_create(arr, sizeof(arr) / sizeof(arr[0]));
    list_t lt    = list_create(target, sizeof(target) / sizeof(target[0]));

    list_t ans = oddEvenList(la);
    ck_assert(list_equal(ans, lt));

    list_free(ans);
    list_free(lt);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
//    tcase_add_test(t, test_official_2);
}