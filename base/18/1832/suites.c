/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/13 下午1:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1832.c"

START_TEST(test_official_1) {
    char *sentence = "thequickbrownfoxjumpsoverthelazydog";
    ck_assert_int_eq(true, checkIfPangram(sentence));
}

START_TEST(test_official_2) {
    char *sentence = "leetcode";
    ck_assert_int_eq(false, checkIfPangram(sentence));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}