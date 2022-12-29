/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/12/29 下午4:34
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2032.c"

int comp(const void *a, const void *b) {
    return *( int * )a - *( int * )b;
}

START_TEST(test_official_1) {
    int nums1[] = { 1, 1, 3, 2 }, nums2[] = { 2, 3 }, nums3[] = { 3 };
    int target[] = { 3, 2 };
    int len, *ans = twoOutOfThree(nums1, LEN(nums1), nums2, LEN(nums2), nums3, LEN(nums3), &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(int), comp);
    qsort(target, len, sizeof(int), comp);
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int nums1[] = { 3, 1 }, nums2[] = { 2, 3 }, nums3[] = { 1, 2 };
    int target[] = { 2, 3, 1 };
    int len, *ans = twoOutOfThree(nums1, LEN(nums1), nums2, LEN(nums2), nums3, LEN(nums3), &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(int), comp);
    qsort(target, len, sizeof(int), comp);
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int nums1[] = { 1, 2, 2 }, nums2[] = { 4, 3, 3 }, nums3[] = { 5 };
    int target[] = {};
    int len, *ans = twoOutOfThree(nums1, LEN(nums1), nums2, LEN(nums2), nums3, LEN(nums3), &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(int), comp);
    qsort(target, len, sizeof(int), comp);
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}