/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/22 上午10:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0725.c"

START_TEST(test_official_1) {
    int len, k = 5, arr[] = { 1, 2, 3 };
    list_t l = list_create(arr);

    list_t target[] = { l, list_find(l, 2), list_find(l, 3), NULL, NULL };
    list_t *ans     = splitListToParts(l, k, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_ptr_eq(ans[i], target[i]);
        list_free(ans[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len, k = 3, arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    list_t l = list_create(arr);

    list_t target[] = { l, list_find(l, 5), list_find(l, 8) };
    list_t *ans     = splitListToParts(l, k, &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_ptr_eq(ans[i], target[i]);
        list_free(ans[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}