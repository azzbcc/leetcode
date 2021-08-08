/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/14 下午3:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0706.c"

START_TEST(test_official) {
    MyHashMap *hash = myHashMapCreate();
    ck_assert_ptr_nonnull(hash);

    myHashMapPut(hash, 1, 1);
    myHashMapPut(hash, 2, 2);
    ck_assert_int_eq(1, myHashMapGet(hash, 1));
    ck_assert_int_eq(-1, myHashMapGet(hash, 3));
    myHashMapPut(hash, 2, 1);
    ck_assert_int_eq(1, myHashMapGet(hash, 2));
    myHashMapRemove(hash, 2);
    ck_assert_int_eq(-1, myHashMapGet(hash, 2));

    myHashMapFree(hash);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}