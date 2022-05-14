/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/5/14 下午6:17
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0691.c"

START_TEST(test_official_1) {
    char *stickers[] = { "with", "example", "science" }, *target = "thehat";
    int k = 3, ans = minStickers(stickers, LEN(stickers), target);
    ck_assert_int_eq(ans, k);
}

START_TEST(test_official_2) {
    char *stickers[] = { "notice","possible" }, *target = "basicbasic";
    int k = -1, ans = minStickers(stickers, LEN(stickers), target);
    ck_assert_int_eq(ans, k);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}