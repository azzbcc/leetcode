/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/14 下午4:06
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0208.c"

START_TEST(test_official) {
    Trie *trie = trieCreate();
    ck_assert_ptr_nonnull(trie);

    trieInsert(trie, "apple");
    ck_assert_int_eq(true, trieSearch(trie, "apple"));
    ck_assert_int_eq(false, trieSearch(trie, "app"));
    ck_assert_int_eq(true, trieStartsWith(trie, "app"));
    trieInsert(trie, "app");
    ck_assert_int_eq(true, trieSearch(trie, "app"));
    trieFree(trie);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}