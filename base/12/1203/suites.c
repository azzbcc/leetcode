/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/1/12 下午3:25
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1203.c"

START_TEST(test_official_1) {
    int len, n = 8, m = 2, group[] = { -1, -1, 1, 0, 0, 1, 0, -1 };
    int col[] = { 0, 1, 1, 1, 2, 0, 0, 0 }, beforeItems[][2] = { {}, { 6 }, { 5 }, { 6 }, { 3, 6 }, {}, {}, {} };
    int *grid[] = { beforeItems[0], beforeItems[1], beforeItems[2], beforeItems[3],
                    beforeItems[4], beforeItems[5], beforeItems[6], beforeItems[7] };

    int target[] = { 0, 5, 2, 6, 3, 4, 7, 1 }, *ans = sortItems(n, m, group, LEN(group), grid, LEN(grid), col, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

START_TEST(test_official_2) {
    int len, n = 8, m = 2, group[] = { -1, -1, 1, 0, 0, 1, 0, -1 };
    int col[] = { 0, 1, 1, 1, 1, 0, 1, 0 }, beforeItems[][1] = { {}, { 6 }, { 5 }, { 6 }, { 3 }, {}, { 4 }, {} };
    int *grid[] = { beforeItems[0], beforeItems[1], beforeItems[2], beforeItems[3],
                    beforeItems[4], beforeItems[5], beforeItems[6], beforeItems[7] };

    int target[] = {}, *ans = sortItems(n, m, group, LEN(group), grid, LEN(grid), col, &len);

    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}