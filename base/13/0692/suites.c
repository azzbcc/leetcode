/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/5/20 下午11:04
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0692.c"

START_TEST(test_official_1) {
    int len, k = 2;
    char *words[]  = { "i", "love", "leetcode", "i", "love", "coding" };
    char *target[] = { "i", "love" };

    char **ans = topKFrequent(words, LEN(words), k, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len, k = 4;
    char *words[]  = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
    char *target[] = { "the", "is", "sunny", "day" };

    char **ans = topKFrequent(words, LEN(words), k, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_failed) {
    int len, k = 14;
    char *words[]  = { "glarko",     "zlfiwwb",    "nsfspyox",   "pwqvwmlgri", "qggx",       "qrkgmliewc", "zskaqzwo",
                      "zskaqzwo",   "ijy",        "htpvnmozay", "jqrlad",     "ccjel",      "qrkgmliewc", "qkjzgws",
                      "fqizrrnmif", "jqrlad",     "nbuorw",     "qrkgmliewc", "htpvnmozay", "nftk",       "glarko",
                      "hdemkfr",    "axyak",      "hdemkfr",    "nsfspyox",   "nsfspyox",   "qrkgmliewc", "nftk",
                      "nftk",       "ccjel",      "qrkgmliewc", "ocgjsu",     "ijy",        "glarko",     "nbuorw",
                      "nsfspyox",   "qkjzgws",    "qkjzgws",    "fqizrrnmif", "pwqvwmlgri", "nftk",       "qrkgmliewc",
                      "jqrlad",     "nftk",       "zskaqzwo",   "glarko",     "nsfspyox",   "zlfiwwb",    "hwlvqgkdbo",
                      "htpvnmozay", "nsfspyox",   "zskaqzwo",   "htpvnmozay", "zskaqzwo",   "nbuorw",     "qkjzgws",
                      "zlfiwwb",    "pwqvwmlgri", "zskaqzwo",   "qengse",     "glarko",     "qkjzgws",    "pwqvwmlgri",
                      "fqizrrnmif", "nbuorw",     "nftk",       "ijy",        "hdemkfr",    "nftk",       "qkjzgws",
                      "jqrlad",     "nftk",       "ccjel",      "qggx",       "ijy",        "qengse",     "nftk",
                      "htpvnmozay", "qengse",     "eonrg",      "qengse",     "fqizrrnmif", "hwlvqgkdbo", "qengse",
                      "qengse",     "qggx",       "qkjzgws",    "qggx",       "pwqvwmlgri", "htpvnmozay", "qrkgmliewc",
                      "qengse",     "fqizrrnmif", "qkjzgws",    "qengse",     "nftk",       "htpvnmozay", "qggx",
                      "zlfiwwb",    "bwp",        "ocgjsu",     "qrkgmliewc", "ccjel",      "hdemkfr",    "nsfspyox",
                      "hdemkfr",    "qggx",       "zlfiwwb",    "nsfspyox",   "ijy",        "qkjzgws",    "fqizrrnmif",
                      "qkjzgws",    "qrkgmliewc", "glarko",     "hdemkfr",    "pwqvwmlgri" };
    char *target[] = { "nftk",   "qkjzgws", "qrkgmliewc", "nsfspyox", "qengse",   "htpvnmozay", "fqizrrnmif",
                       "glarko", "hdemkfr", "pwqvwmlgri", "qggx",     "zskaqzwo", "ijy",        "zlfiwwb" };

    char **ans = topKFrequent(words, LEN(words), k, &len);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
//    tcase_add_test(t, test_official_1);
//    tcase_add_test(t, test_official_2);
}