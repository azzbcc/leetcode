/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/4/12 下午1:42
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1815.c"

START_TEST(test_official_1) {
    int batch = 3, arr[] = { 1, 2, 3, 4, 5, 6 };
    int target = 4, ans = maxHappyGroups(batch, arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int batch = 4, arr[] = { 1, 3, 2, 5, 2, 2, 1, 6 };
    int target = 4, ans = maxHappyGroups(batch, arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int batch = 2, arr[] = { 652231582, 818492002, 823729239, 2261354,   747144855, 478230860, 285970257, 774747712,
                             860954510, 245631565, 634746161, 109765576, 967900367, 340837477, 32845752,  23968185 };
    int target = 12, ans = maxHappyGroups(batch, arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int batch  = 7,
        arr[]  = { 145326640, 622724151, 591814792, 827053040, 111964428, 344376875, 42023891,  436582274, 78590835,
                  408269112, 930041188, 846233596, 158192647, 889601516, 134236253, 366035866, 123146762 };
    int target = 9, ans = maxHappyGroups(batch, arr, LEN(arr));
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}