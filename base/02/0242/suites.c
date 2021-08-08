/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/22 下午7:53
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0242.c"

START_TEST(test_official_1) {
    char *s = "anagram", *t = "nagaram";

    bool target = true, ans = isAnagram(s, t);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    char *s = "rat", *t = "car";

    bool target = false, ans = isAnagram(s, t);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}