/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/10/12 下午12:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <list.h>

#include "0817.c"

START_TEST(test_official_1) {
    int head[] = { 0, 1, 2, 3 }, nums[] = { 0, 1, 3 };
    list_t l   = list_create(head);
    int target = 2, ans = numComponents(l, nums, LEN(nums));
    ck_assert_int_eq(ans, target);
    list_free(l);
}

START_TEST(test_official_2) {
    int head[] = { 0, 1, 2, 3, 4 }, nums[] = { 0, 3, 1, 4 };
    list_t l   = list_create(head);
    int target = 2, ans = numComponents(l, nums, LEN(nums));
    ck_assert_int_eq(ans, target);
    list_free(l);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}