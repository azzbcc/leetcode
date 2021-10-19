/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/10/19 上午10:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0211.c"

START_TEST(test_official) {
    WordDictionary *dict = wordDictionaryCreate();
    ck_assert_ptr_nonnull(dict);

    wordDictionaryAddWord(dict, "bad");
    wordDictionaryAddWord(dict, "dad");
    wordDictionaryAddWord(dict, "mad");
    ck_assert_int_eq(false, wordDictionarySearch(dict, "pad"));
    ck_assert_int_eq(true, wordDictionarySearch(dict, "bad"));
    ck_assert_int_eq(true, wordDictionarySearch(dict, ".ad"));
    ck_assert_int_eq(true, wordDictionarySearch(dict, "b.."));

    wordDictionaryFree(dict);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}