/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/9 下午5:55
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0146.c"

START_TEST(test_official) {
    LRUCache *cache = lRUCacheCreate(2);

    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 2);
    ck_assert_int_eq(lRUCacheGet(cache, 1), 1);
    lRUCachePut(cache, 3, 3);
    ck_assert_int_eq(lRUCacheGet(cache, 2), -1);
    lRUCachePut(cache, 4, 4);
    ck_assert_int_eq(lRUCacheGet(cache, 1), -1);
    ck_assert_int_eq(lRUCacheGet(cache, 3), 3);
    ck_assert_int_eq(lRUCacheGet(cache, 4), 4);

    lRUCacheFree(cache);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}