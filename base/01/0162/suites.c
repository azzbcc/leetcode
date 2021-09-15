/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/9/15 上午10:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0162.c"

int array_cmp(const void *a, const void *key) {
    return *( int * )a - *( int * )key;
}

START_TEST(test_official_1) {
    int arr[]    = { 1, 2, 3, 1 };
    int target[] = { 2 }, ans = findPeakElement(arr, LEN(arr));
    ck_assert_ptr_nonnull(bsearch(&ans, target, LEN(target), sizeof(int), array_cmp));
}

START_TEST(test_official_2) {
    int arr[]    = { 1, 2, 1, 3, 5, 6, 4 };
    int target[] = { 1, 5 }, ans = findPeakElement(arr, LEN(arr));
    ck_assert_ptr_nonnull(bsearch(&ans, target, LEN(target), sizeof(int), array_cmp));
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}