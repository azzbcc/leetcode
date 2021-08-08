/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/26 下午12:30
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1178.c"

START_TEST(test_official) {
    char *word[]    = { "aaaa", "asas", "able", "ability", "actt", "actor", "access" };
    char *puzzles[] = { "aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz" };
    int target[]    = { 1, 1, 3, 2, 4, 0 };
    int len, *ans = findNumOfValidWords(word, LEN(word), puzzles, LEN(puzzles), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    char *word[]    = { "apple", "pleas", "please" };
    char *puzzles[] = { "aelwxyz", "aelpxyz", "aelpsxy", "saelpxy", "xaelpsy" };
    int target[]    = { 0, 1, 3, 2, 0 };
    int len, *ans = findNumOfValidWords(word, LEN(word), puzzles, LEN(puzzles), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_tle) {
#include "tle.c"
    int len, *ans = findNumOfValidWords(word, LEN(word), puzzles, LEN(puzzles), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}
