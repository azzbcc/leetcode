/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/12/21 13:27
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "2866.c"

START_TEST(test_official_1) {
    int maxHeights[] = { 5, 3, 4, 1, 1 };
    long long target = 13, ans = maximumSumOfHeights(maxHeights, LEN(maxHeights));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int maxHeights[] = { 6, 5, 3, 9, 2, 7 };
    long long target = 22, ans = maximumSumOfHeights(maxHeights, LEN(maxHeights));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int maxHeights[] = { 3, 2, 5, 5, 2, 3 };
    long long target = 18, ans = maximumSumOfHeights(maxHeights, LEN(maxHeights));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}