/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/4/21 下午12:27
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0824.c"

START_TEST(test_official_1) {
    char *sentence = "I speak Goat Latin";
    char *target   = "Imaa peaksmaaa oatGmaaaa atinLmaaaaa";
    char *ans      = toGoatLatin(sentence);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char *sentence = "The quick brown fox jumped over the lazy dog";
    char *target =
        "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa";
    char *ans = toGoatLatin(sentence);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_limit) {
    char sentence[151] = "aa";
    for (int i = 1; i < 75; sentence[i * 2] = ' ', sentence[i * 2 + 1] = 'a', ++i) {}

    char *target =
        "aamaa amaaa amaaaa amaaaaa amaaaaaa amaaaaaaa amaaaaaaaa amaaaaaaaaa amaaaaaaaaaa amaaaaaaaaaaa "
        "amaaaaaaaaaaaa amaaaaaaaaaaaaa amaaaaaaaaaaaaaa amaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa "
        "amaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char *ans = toGoatLatin(sentence);

    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_limit);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}