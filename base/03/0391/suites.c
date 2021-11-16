/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/11/16 下午2:01
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0391.c"

START_TEST(test_official_1) {
    int *rectangles[] = { (int[]) { 1, 1, 3, 3 }, (int[]) { 3, 1, 4, 2 }, (int[]) { 3, 2, 4, 4 },
                          (int[]) { 1, 3, 2, 4 }, (int[]) { 2, 3, 3, 4 } };
    bool target = true, ans = isRectangleCover(rectangles, LEN(rectangles), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int *rectangles[] = { (int[]) { 1, 1, 2, 3 }, (int[]) { 1, 3, 2, 4 }, (int[]) { 3, 1, 4, 2 },
                          (int[]) { 3, 2, 4, 4 } };
    bool target = false, ans = isRectangleCover(rectangles, LEN(rectangles), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int *rectangles[] = { (int[]) { 1, 1, 3, 3 }, (int[]) { 3, 1, 4, 2 }, (int[]) { 1, 3, 2, 4 },
                          (int[]) { 3, 2, 4, 4 } };
    bool target = false, ans = isRectangleCover(rectangles, LEN(rectangles), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_4) {
    int *rectangles[] = { (int[]) { 1, 1, 3, 3 }, (int[]) { 3, 1, 4, 2 }, (int[]) { 1, 3, 2, 4 },
                          (int[]) { 2, 2, 4, 4 } };
    bool target = false, ans = isRectangleCover(rectangles, LEN(rectangles), NULL);
    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int *rectangles[] = { (int[]) { 0, 0, 1, 1 }, (int[]) { 0, 0, 1, 1 }, (int[]) { 1, 1, 2, 2 },
                          (int[]) { 1, 1, 2, 2 } };
    bool target = false, ans = isRectangleCover(rectangles, LEN(rectangles), NULL);
    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
    tcase_add_test(t, test_official_4);
}