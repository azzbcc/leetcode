/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/10/31 14:41
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2003.c"

START_TEST(test_official_1) {
    int len;
    int parents[] = { -1, 0, 0, 2 }, nums[] = { 1, 2, 3, 4 };
    int target[] = { 5, 1, 1, 1 }, *ans = smallestMissingValueSubtree(parents, LEN(parents), nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    int parents[] = { -1, 0, 1, 0, 3, 3 }, nums[] = { 5, 4, 6, 2, 1, 3 };
    int target[] = { 7, 1, 1, 4, 2, 1 },
        *ans     = smallestMissingValueSubtree(parents, LEN(parents), nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int len;
    int parents[] = { -1, 2, 3, 0, 2, 4, 1 }, nums[] = { 2, 3, 4, 5, 6, 7, 8 };
    int target[] = { 1, 1, 1, 1, 1, 1, 1 },
        *ans     = smallestMissingValueSubtree(parents, LEN(parents), nums, LEN(nums), &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}