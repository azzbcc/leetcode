/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/2/1 下午2:19
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2325.c"

START_TEST(test_official_1) {
    char *key = "the quick brown fox jumps over the lazy dog", *message = "vkbs bs t suepuv";
    char *target = "this is a secret", *ans = decodeMessage(key, message);
    ck_assert_str_eq(ans, target);
    free(ans);
}

START_TEST(test_official_2) {
    char *key = "eljuxhpwnyrdgtqkviszcfmabo", *message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";
    char *target = "the five boxing wizards jump quickly", *ans = decodeMessage(key, message);
    ck_assert_str_eq(ans, target);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}