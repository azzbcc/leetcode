/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/11/25 下午8:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0809.c"

START_TEST(test_official) {
    char *s = "heeellooo", *words[] = { "hello", "hi", "helo" };
    int target = 1, ans = expressiveWords(s, words, LEN(words));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}