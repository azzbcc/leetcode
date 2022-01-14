/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/1/14 下午8:43
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0373.c"

START_TEST(test_official_1) {
    int len = 0, *returnColumnSizes = NULL;
    int nums1[] = { 1, 7, 11 }, nums2[] = { 2, 4, 6 }, k = 3;
    int *target[] = { (int[]) { 1, 2 }, (int[]) { 1, 4 }, (int[]) { 1, 6 } };
    int **ans     = kSmallestPairs(nums1, LEN(nums1), nums2, LEN(nums2), k, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

START_TEST(test_official_2) {
    int len = 0, *returnColumnSizes = NULL;
    int nums1[] = { 1, 1, 2 }, nums2[] = { 1, 2, 3 }, k = 2;
    int *target[] = { (int[]) { 1, 1 }, (int[]) { 1, 1 } };
    int **ans     = kSmallestPairs(nums1, LEN(nums1), nums2, LEN(nums2), k, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

START_TEST(test_official_3) {
    int len = 0, *returnColumnSizes = NULL;
    int nums1[] = { 1, 2 }, nums2[] = { 3 }, k = 3;
    int *target[] = { (int[]) { 1, 3 }, (int[]) { 2, 3 } };
    int **ans     = kSmallestPairs(nums1, LEN(nums1), nums2, LEN(nums2), k, &len, &returnColumnSizes);
    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
        free(ans[i]);
    }
    free(returnColumnSizes);
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}