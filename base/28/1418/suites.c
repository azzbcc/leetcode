/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/7/6 下午2:18
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1418.c"

START_TEST(test_official_1) {
    int len = 0, *returnColumnSizes = NULL, col = 5;
    char **orders[] = { (char *[]) { "David", "3", "Ceviche" },       (char *[]) { "Corina", "10", "Beef Burrito" },
                        (char *[]) { "David", "3", "Fried Chicken" }, (char *[]) { "Carla", "5", "Water" },
                        (char *[]) { "Carla", "5", "Ceviche" },       (char *[]) { "Rous", "3", "Ceviche" } };
    char **target[] = { (char *[]) { "Table", "Beef Burrito", "Ceviche", "Fried Chicken", "Water" },
                        (char *[]) { "3", "0", "2", "1", "0" }, (char *[]) { "5", "0", "1", "0", "1" },
                        (char *[]) { "10", "1", "0", "0", "0" } };
    char ***ans     = displayTable(orders, LEN(orders), NULL, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col);
        for (int j = 0; j < col; ++j) {
            ck_assert_str_eq(ans[i][j], target[i][j]);
            free(ans[i][j]);
        }
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int len = 0, *returnColumnSizes = NULL, col = 3;
    char **orders[] = { (char *[]) { "James", "12", "Fried Chicken" }, (char *[]) { "Ratesh", "12", "Fried Chicken" },
                        (char *[]) { "Amadeus", "12", "Fried Chicken" }, (char *[]) { "Adam", "1", "Canadian Waffles" },
                        (char *[]) { "Brianna", "1", "Canadian Waffles" } };
    char **target[] = { (char *[]) { "Table", "Canadian Waffles", "Fried Chicken" }, (char *[]) { "1", "2", "0" },
                        (char *[]) { "12", "0", "3" } };
    char ***ans     = displayTable(orders, LEN(orders), NULL, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col);
        for (int j = 0; j < col; ++j) {
            ck_assert_str_eq(ans[i][j], target[i][j]);
            free(ans[i][j]);
        }
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_3) {
    int len = 0, *returnColumnSizes = NULL, col = 4;
    char **orders[] = { (char *[]) { "Laura", "2", "Bean Burrito" }, (char *[]) { "Jhon", "2", "Beef Burrito" },
                        (char *[]) { "Melissa", "2", "Soda" } };
    char **target[] = { (char *[]) { "Table", "Bean Burrito", "Beef Burrito", "Soda" },
                        (char *[]) { "2", "1", "1", "1" } };
    char ***ans     = displayTable(orders, LEN(orders), NULL, &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], col);
        for (int j = 0; j < col; ++j) {
            ck_assert_str_eq(ans[i][j], target[i][j]);
            free(ans[i][j]);
        }
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}