/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/4/23 下午2:52
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1105.c"

START_TEST(test_official_1) {
    int shelfWidth = 4;
    int *books[]   = { (int[]) { 1, 1 }, (int[]) { 2, 3 }, (int[]) { 2, 3 }, (int[]) { 1, 1 },
                       (int[]) { 1, 1 }, (int[]) { 1, 1 }, (int[]) { 1, 2 } };
    int target = 6, ans = minHeightShelves(books, LEN(books), NULL, shelfWidth);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int shelfWidth = 6;
    int *books[]   = { (int[]) { 1, 3 }, (int[]) { 2, 4 }, (int[]) { 3, 2 } };
    int target = 4, ans = minHeightShelves(books, LEN(books), NULL, shelfWidth);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}