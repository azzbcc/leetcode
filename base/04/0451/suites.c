/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/29 下午1:37
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0451.c"

START_TEST(test_official_1) {
    char str[] = "tree";

    char *target = "eert", *ans = frequencySort(str);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_official_2) {
    char str[] = "cccaaa";

    char *target = "aaaccc", *ans = frequencySort(str);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_official_3) {
    char str[] = "Aabb";

    char *target = "bbAa", *ans = frequencySort(str);

    ck_assert_str_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}