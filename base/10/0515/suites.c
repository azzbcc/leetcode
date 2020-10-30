/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/30 下午4:45
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0515.c"

START_TEST(test_official) {
    int len, arr[] = { 1, 3, 2, 5, 3, null, 9 };
    tree_t t = tree_create(arr);

    int target[] = { 1, 3, 9 }, *ans = largestValues(t, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    tree_free(t);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}