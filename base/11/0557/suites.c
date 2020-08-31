/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/29 下午17:44
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0557.c"

START_TEST(test_official) {
    char input[] = "Let's take LeetCode contest";
    char *target = "s'teL ekat edoCteeL tsetnoc", *ans = reverseWords(input);

    ck_assert_str_eq(target, ans);
}
void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}