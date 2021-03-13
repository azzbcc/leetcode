/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/3/13 下午2:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0705.c"

START_TEST(test_official) {
    MyHashSet *hash = myHashSetCreate();
    ck_assert_ptr_nonnull(hash);

    myHashSetAdd(hash, 1);
    myHashSetAdd(hash, 2);
    ck_assert_int_eq(true, myHashSetContains(hash, 1));
    ck_assert_int_eq(false, myHashSetContains(hash, 3));
    myHashSetAdd(hash, 2);
    ck_assert_int_eq(true, myHashSetContains(hash, 2));
    myHashSetRemove(hash, 2);
    ck_assert_int_eq(false, myHashSetContains(hash, 2));

    myHashSetFree(hash);
}

void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
START_TEST(test_own) {
    int sn[100];

    MyHashSet *hash = myHashSetCreate();
    ck_assert_ptr_nonnull(hash);

    for (int i = 0; i < LEN(sn); ++i) {
        sn[i] = i * SIZE;
    }
    for (int i = LEN(sn) - 1; i > 0; --i) {
        swap(&sn[rand() % (i + 1)], &sn[i]);
    }
    for (int i = 0; i < LEN(sn); ++i) {
        myHashSetAdd(hash, sn[i]);
    }
    for (int i = 0; i < LEN(sn); ++i) {
        ck_assert_int_eq(true, myHashSetContains(hash, sn[i]));
    }

    myHashSetFree(hash);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official);
}