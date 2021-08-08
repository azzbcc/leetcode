/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/21 下午4:12
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0728.c"

START_TEST(test_official) {
    int target[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22 };
    int len, *ans = selfDividingNumbers(1, 22, &len);

    ck_assert_int_eq(len, sizeof(target) / sizeof(target[0]));
    ck_assert_mem_eq(target, ans, sizeof(target));

    free(ans);
}

void tcase_complete(TCase *t) {
    int len, *ans = selfDividingNumbers(1, 10000, &len);

    for (int i = 0; i < len; ++i) {
        printf("%4d%s", ans[i], i % 10 == 9 ? "\n" : ", ");
    }

    free(ans);
    tcase_add_test(t, test_official);
}
