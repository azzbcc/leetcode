/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/10/22 上午11:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0763.c"

START_TEST(test_official) {
    char *s = "ababcbacadefegdehijhklij";

    int target[] = { 9, 7, 8 };
    int len, *ans = partitionLabels(s, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_failed) {
    char *s = "eccbbbbdec";

    int target[] = { 10 };
    int len, *ans = partitionLabels(s, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official);
}