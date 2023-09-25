/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/9/25 15:01
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0460.c"

#define null INT32_MIN
START_TEST(test_official) {
    LFUCache *cache = lFUCacheCreate(2);
    ck_assert_ptr_nonnull(cache);

    char *commands[] = { "put", "put", "get", "put", "get", "get", "put", "get", "get", "get" };
    int *argv[]      = { (int[]) { 1, 1 }, (int[]) { 2, 2 }, (int[]) { 1, 1 },  (int[]) { 3, 3 }, (int[]) { 2, -1 },
                         (int[]) { 3, 3 }, (int[]) { 4, 4 }, (int[]) { 1, -1 }, (int[]) { 3, 3 }, (int[]) { 4, 4 } };
    for (int i = 0; i < LEN(commands); ++i) {
        if (!strcmp(commands[i], "get")) {
            ck_assert_int_eq(lFUCacheGet(cache, argv[i][0]), argv[i][1]);
        } else if (!strcmp(commands[i], "put")) {
            lFUCachePut(cache, argv[i][0], argv[i][1]);
        } else {
            ck_abort_msg("error command: %s\n", commands[i]);
        }
    }
    lFUCacheFree(cache);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}