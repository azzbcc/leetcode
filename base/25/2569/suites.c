/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/7/26 15:07
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2569.c"

START_TEST(test_official_1) {
    int len;
    int nums1[] = { 1, 0, 1 }, nums2[] = { 0, 0, 0 };
    int *queries[]     = { (int[]) { 1, 1, 1 }, (int[]) { 2, 1, 0 }, (int[]) { 3, 0, 0 } };
    long long target[] = { 3 };
    long long *ans     = handleQuery(nums1, LEN(nums1), nums2, LEN(nums2), queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    int nums1[] = { 1 }, nums2[] = { 5 };
    int *queries[]     = { (int[]) { 2, 0, 0 }, (int[]) { 3, 0, 0 } };
    long long target[] = { 5 };
    long long *ans     = handleQuery(nums1, LEN(nums1), nums2, LEN(nums2), queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_failed) {
    int len;
    int nums1[]        = { 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1 };
    int nums2[]        = { 30, 46, 43, 34, 39, 16, 14, 41, 22, 11, 32, 2, 44, 12, 22, 36, 44, 49, 50, 10, 33, 7, 42 };
    int *queries[]     = { (int[]) { 1, 15, 21 }, (int[]) { 3, 0, 0 },  (int[]) { 3, 0, 0 },
                           (int[]) { 2, 21, 0 },  (int[]) { 2, 13, 0 }, (int[]) { 3, 0, 0 } };
    long long target[] = { 679, 679, 1053 };
    long long *ans     = handleQuery(nums1, LEN(nums1), nums2, LEN(nums2), queries, LEN(queries), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}