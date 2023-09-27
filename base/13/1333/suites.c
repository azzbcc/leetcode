/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/9/27 15:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1333.c"

START_TEST(test_official_1) {
    int *restaurants[] = { (int[]) { 1, 4, 1, 40, 10 }, (int[]) { 2, 8, 0, 50, 5 }, (int[]) { 3, 8, 1, 30, 4 },
                           (int[]) { 4, 10, 0, 10, 3 }, (int[]) { 5, 1, 1, 15, 1 } };
    int veganFriendly = 1, maxPrice = 50, maxDistance = 10;
    int len, target[] = { 3, 1, 5 };
    int *ans = filterRestaurants(restaurants, LEN(restaurants), NULL, veganFriendly, maxPrice, maxDistance, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int *restaurants[] = { (int[]) { 1, 4, 1, 40, 10 }, (int[]) { 2, 8, 0, 50, 5 }, (int[]) { 3, 8, 1, 30, 4 },
                           (int[]) { 4, 10, 0, 10, 3 }, (int[]) { 5, 1, 1, 15, 1 } };
    int veganFriendly = 0, maxPrice = 50, maxDistance = 10;
    int len, target[] = { 4, 3, 2, 1, 5 };
    int *ans = filterRestaurants(restaurants, LEN(restaurants), NULL, veganFriendly, maxPrice, maxDistance, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_3) {
    int *restaurants[] = { (int[]) { 1, 4, 1, 40, 10 }, (int[]) { 2, 8, 0, 50, 5 }, (int[]) { 3, 8, 1, 30, 4 },
                           (int[]) { 4, 10, 0, 10, 3 }, (int[]) { 5, 1, 1, 15, 1 } };
    int veganFriendly = 0, maxPrice = 30, maxDistance = 3;
    int len, target[] = { 4, 5 };
    int *ans = filterRestaurants(restaurants, LEN(restaurants), NULL, veganFriendly, maxPrice, maxDistance, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}