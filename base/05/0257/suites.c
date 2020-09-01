/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/1 下午7:02
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <tree.h>

#include "0257.c"

START_TEST(test_official) {
    int len, arr[] = { 1, 2, 3, null, 5 };
    tree_t t       = tree_create(arr, 0, sizeof(arr) / sizeof(arr[0]));
    char *target[] = { "1->2->5", "1->3" }, **ans = binaryTreePaths(t, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(target[i], ans[i]);
        free(ans[i]);
    }
    free(ans);
    tree_free(t);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}
