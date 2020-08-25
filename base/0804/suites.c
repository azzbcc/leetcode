/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/25 下午6:04
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0804.c"

START_TEST(test_official) {
    char *words[] = { "gin", "zen", "gig", "msg" };

    int target = 2, ans = uniqueMorseRepresentations(words, sizeof(words) / sizeof(words[0]));

    ck_assert_int_eq(target, ans);
}

START_TEST(test_failed) {
    char *words[] = { "a" };

    int target = 1, ans = uniqueMorseRepresentations(words, sizeof(words) / sizeof(words[0]));

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}