/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/9/14 16:24
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1222.c"

START_TEST(test_official_1) {
    int len, *returnColumnSizes;
    int *queens[] = { (int[]) { 0, 1 }, (int[]) { 1, 0 }, (int[]) { 4, 0 },
                      (int[]) { 0, 4 }, (int[]) { 3, 3 }, (int[]) { 2, 4 } };
    int king[]    = { 0, 0 };
    int *target[] = { (int[]) { 0, 1 }, (int[]) { 1, 0 }, (int[]) { 3, 3 } };
    int **ans     = queensAttacktheKing(queens, LEN(queens), NULL, king, LEN(king), &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_2) {
    int len, *returnColumnSizes;
    int *queens[] = { (int[]) { 0, 0 }, (int[]) { 1, 1 }, (int[]) { 2, 2 }, (int[]) { 3, 4 },
                      (int[]) { 3, 5 }, (int[]) { 4, 4 }, (int[]) { 4, 5 } };
    int king[]    = { 3, 3 };
    int *target[] = { (int[]) { 2, 2 }, (int[]) { 3, 4 }, (int[]) { 4, 4 } };
    int **ans     = queensAttacktheKing(queens, LEN(queens), NULL, king, LEN(king), &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);
}

START_TEST(test_official_3) {
    int len, *returnColumnSizes;
    int *queens[] = { (int[]) { 5, 6 }, (int[]) { 7, 7 }, (int[]) { 2, 1 }, (int[]) { 0, 7 }, (int[]) { 1, 6 },
                      (int[]) { 5, 1 }, (int[]) { 3, 7 }, (int[]) { 0, 3 }, (int[]) { 4, 0 }, (int[]) { 1, 2 },
                      (int[]) { 6, 3 }, (int[]) { 5, 0 }, (int[]) { 0, 4 }, (int[]) { 2, 2 }, (int[]) { 1, 1 },
                      (int[]) { 6, 4 }, (int[]) { 5, 4 }, (int[]) { 0, 0 }, (int[]) { 2, 6 }, (int[]) { 4, 5 },
                      (int[]) { 5, 2 }, (int[]) { 1, 4 }, (int[]) { 7, 5 }, (int[]) { 2, 3 }, (int[]) { 0, 5 },
                      (int[]) { 4, 2 }, (int[]) { 1, 0 }, (int[]) { 2, 7 }, (int[]) { 0, 1 }, (int[]) { 4, 6 },
                      (int[]) { 6, 1 }, (int[]) { 0, 6 }, (int[]) { 4, 3 }, (int[]) { 1, 7 } };
    int king[]    = { 3, 4 };
    int *target[] = { (int[]) { 2, 3 }, (int[]) { 1, 4 }, (int[]) { 1, 6 }, (int[]) { 3, 7 },
                      (int[]) { 4, 3 }, (int[]) { 5, 4 }, (int[]) { 4, 5 } };
    int **ans     = queensAttacktheKing(queens, LEN(queens), NULL, king, LEN(king), &len, &returnColumnSizes);

    ck_assert_int_eq(len, LEN(target));
    for (int i = 0; i < len; ++i) {
        ck_assert_int_eq(returnColumnSizes[i], 2);
        ck_assert_mem_eq(ans[i], target[i], 2 * sizeof(int));
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