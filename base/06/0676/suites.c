/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/9/27 下午5:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */

#include <common.h>

#include "0676.c"

START_TEST(test_official) {
    char *dict[] = { "hello", "leetcode" };

    MagicDictionary *dictionary = magicDictionaryCreate();
    magicDictionaryBuildDict(dictionary, dict, sizeof(dict) / sizeof(dict[0]));

    ck_assert_int_eq(false, magicDictionarySearch(dictionary, "hello"));
    ck_assert_int_eq(true, magicDictionarySearch(dictionary, "hhllo"));
    ck_assert_int_eq(false, magicDictionarySearch(dictionary, "hell"));
    ck_assert_int_eq(false, magicDictionarySearch(dictionary, "leetcoded"));

    magicDictionaryFree(dictionary);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}