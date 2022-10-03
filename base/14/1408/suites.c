/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/8/6 上午1:31
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1408.c"

START_TEST(test_official_1) {
    int len;
    char *words[]  = { "mass", "as", "hero", "superhero" };
    char *target[] = { "as", "hero" };
    char **ans     = stringMatching(words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_ptr_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char *words[]  = { "leetcode", "et", "code" };
    char *target[] = { "et", "code" };
    char **ans     = stringMatching(words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_ptr_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_3) {
    int len;
    char *words[]  = { "blue", "green", "bu" };
    char *target[] = {};
    char **ans     = stringMatching(words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_ptr_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_failed) {
    int len;
    char *words[]  = { "leetcoder", "leetcode", "od", "hamlet", "am" };
    char *target[] = { "leetcode", "od", "am" };
    char **ans     = stringMatching(words, LEN(words), &len);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_ptr_eq(ans[i], target[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}