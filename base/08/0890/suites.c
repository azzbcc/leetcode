/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/6/12 上午10:54
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0890.c"

START_TEST(test_official) {
    int len;
    char *words[] = { "abc", "deq", "mee", "aqq", "dkd", "ccc" }, *pattern = "abb";
    char *target[] = { "mee", "aqq" }, **ans = findAndReplacePattern(words, LEN(words), pattern, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}