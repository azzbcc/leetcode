/**
 * suites.c
 * Copyright(c) 2024 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2024/4/10 14:57
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1702.c"

START_TEST(test_official_1) {
    char binary[] = "000110";
    char *target = "111011", *ans = maximumBinaryString(binary);
    ck_assert_str_eq(ans, target);
}

START_TEST(test_official_2) {
    char binary[] = "01";
    char *target = "01", *ans = maximumBinaryString(binary);
    ck_assert_str_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}