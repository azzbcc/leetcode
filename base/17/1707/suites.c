/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/5/23 下午12:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1707.c"

START_TEST(test_official_1) {
    int nums[]     = { 0, 1, 2, 3, 4 };
    int *queries[] = { (int[]) { 3, 1 }, (int[]) { 1, 3 }, (int[]) { 5, 6 } };
    int target[]   = { 3, 3, 7 };
    int len, *ans = maximizeXor(nums, LEN(nums), queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int nums[]     = { 5, 2, 4, 6, 6, 3 };
    int *queries[] = { (int[]) { 12, 4 }, (int[]) { 8, 1 }, (int[]) { 6, 3 } };
    int target[]   = { 15, -1, 5 };
    int len, *ans = maximizeXor(nums, LEN(nums), queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int nums[]     = { 536870912, 0, 534710168, 330218644, 142254206 };
    int *queries[] = { (int[]) { 558240772, 1000000000 }, (int[]) { 307628050, 1000000000 },
                       (int[]) { 3319300, 1000000000 }, (int[]) { 2751604, 683297522 }, (int[]) { 214004, 404207941 } };
    int target[]   = { 1050219420, 844498962, 540190212, 539622516, 330170208 };
    int len, *ans = maximizeXor(nums, LEN(nums), queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_tle) {
#include "tle.c"
    int *queries[] = { (int[]) { 1000000000, 1000000000 } };
    int target[]   = { 1073736192 };
    int len, *ans = maximizeXor(nums, LEN(nums), queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}