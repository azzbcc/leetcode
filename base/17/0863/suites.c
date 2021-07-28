/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/28 上午11:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0863.c"

static int cmp_array(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}
START_TEST(test_official) {
    int K = 2, arr[] = { 3, 5, 1, 6, 2, 0, 8, null, null, 7, 4 };
    tree_t t = tree_create(arr), find = tree_find(t, 5);
    int target[] = { 7, 4, 1 };

    int len, *ans = distanceK(t, find, K, &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(int), cmp_array);
    qsort(target, len, sizeof(int), cmp_array);
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}