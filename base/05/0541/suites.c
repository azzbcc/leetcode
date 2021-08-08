/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/29 下午8:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0541.c"

START_TEST(test_official) {
    char str[] = "abcdefg";

    char *target = "bacdfeg", *ans = reverseStr(str, 2);

    ck_assert_str_eq(target, ans);
}

START_TEST(test_failed) {
    char str[] = "krmyfshbspcgtesxnnljhfursyissjnsocgdhgfxubewllxzqhpasguvlrxtkgatzfybprfmmfithphckksnvjkcvnsqgsgosfxc";
    char *tar  = "jlnnxsetgcpsbhsfymrkhfursyissjnsocgdhgfxtxrlvugsaphqzxllwebukgatzfybprfmmfithphccxfsogsgqsnvckjvnskk";

    char *ans = reverseStr(str, 20);

    ck_assert_str_eq(tar, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}