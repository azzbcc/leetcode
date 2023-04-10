/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/10 下午9:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "1019.c"

START_TEST(test_official_1) {
    int arr[] = { 2, 1, 5 };
    list_t l  = list_create(arr);

    int target[] = { 5, 5, 0 };
    int len, *ans = nextLargerNodes(l, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    list_free(l);
    free(ans);
}

START_TEST(test_official_2) {
    int arr[] = { 2, 7, 4, 3, 5 };
    list_t l  = list_create(arr);

    int target[] = { 7, 0, 5, 5, 0 };
    int len, *ans = nextLargerNodes(l, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    list_free(l);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}