/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/30 下午4:26
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1433.c"

START_TEST(test_official_1) {
    char s1[] = "abc", s2[] = "xya";

    bool target = true, ans = checkIfCanBreak(s1, s2);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_2) {
    char s1[] = "abe", s2[] = "acd";

    bool target = false, ans = checkIfCanBreak(s1, s2);

    ck_assert_int_eq(target, ans);
}

START_TEST(test_official_3) {
    char s1[] = "leetcodee", s2[] = "interview";

    bool target = true, ans = checkIfCanBreak(s1, s2);

    ck_assert_int_eq(target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}
