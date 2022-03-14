/**
 * suites.c
 * Copyright(c) 2022 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2022/3/14 上午11:13
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0599.c"

int comp(const void *a, const void *b) {
    return strcmp(*( char ** )a, *( char ** )b);
}

START_TEST(test_official_1) {
    int len;
    char *list1[]  = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
    char *list2[]  = { "Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun" };
    char *target[] = { "Shogun" };
    char **ans     = findRestaurant(list1, LEN(list1), list2, LEN(list2), &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(ans[0]), comp);
    qsort(target, len, sizeof(target[0]), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

START_TEST(test_official_2) {
    int len;
    char *list1[]  = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
    char *list2[]  = { "KFC", "Shogun", "Burger King" };
    char *target[] = { "Shogun" };
    char **ans     = findRestaurant(list1, LEN(list1), list2, LEN(list2), &len);

    ck_assert_int_eq(len, LEN(target));
    qsort(ans, len, sizeof(ans[0]), comp);
    qsort(target, len, sizeof(target[0]), comp);
    for (int i = 0; i < len; ++i) {
        ck_assert_str_eq(ans[i], target[i]);
    }
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}