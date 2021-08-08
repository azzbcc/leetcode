/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/6/22 下午7:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1389.c"

START_TEST(test_official_1) {
    int nums[] = { 0, 1, 2, 3, 4 }, index[] = { 0, 1, 2, 2, 1 }, target[] = { 0, 4, 1, 3, 2 };
    int len, *ans = createTargetArray(nums, LEN(nums), index, LEN(index), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int nums[] = { 1, 2, 3, 4, 0 }, index[] = { 0, 1, 2, 3, 0 }, target[] = { 0, 1, 2, 3, 4 };
    int len, *ans = createTargetArray(nums, LEN(nums), index, LEN(index), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int nums[] = { 1 }, index[] = { 0 }, target[] = { 1 };
    int len, *ans = createTargetArray(nums, LEN(nums), index, LEN(index), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}