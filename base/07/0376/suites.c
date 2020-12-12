/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/12 下午1:47
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0376.c"

START_TEST(test_official_1) {
    int arr[]  = { 1, 7, 4, 9, 2, 5 };
    int target = 6, ans = wiggleMaxLength(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[]  = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
    int target = 7, ans = wiggleMaxLength(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[]  = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int target = 2, ans = wiggleMaxLength(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_own) {
    int arr[]  = { 1, 1, 1, 1, 1, 1, 1 };
    int target = 1, ans = wiggleMaxLength(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed) {
    int arr[]  = { 3, 3, 3, 2, 5 };
    int target = 3, ans = wiggleMaxLength(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle) {
    int arr[]  = { 51,  226, 208, 165, 202, 286, 190, 212, 219, 271, 36,  245, 20,  238, 238, 89,  105, 66,  73,  9,
                  254, 206, 221, 237, 203, 33,  249, 253, 150, 102, 57,  249, 203, 10,  123, 178, 85,  203, 35,  276,
                  129, 116, 37,  163, 99,  142, 187, 249, 134, 77,  217, 298, 29,  127, 174, 115, 122, 178, 12,  80,
                  122, 76,  16,  41,  115, 84,  104, 121, 127, 40,  287, 129, 9,   172, 112, 51,  40,  135, 205, 53,
                  259, 196, 248, 5,   123, 184, 209, 130, 271, 42,  18,  143, 24,  101, 10,  273, 252, 50,  173, 80,
                  119, 129, 45,  257, 299, 78,  278, 78,  190, 215, 284, 129, 200, 232, 103, 97,  167, 120, 49,  298,
                  141, 146, 154, 233, 214, 196, 244, 50,  110, 48,  152, 82,  226, 26,  254, 276, 292, 286, 215, 56,
                  128, 122, 82,  241, 222, 12,  272, 192, 224, 136, 116, 70,  39,  207, 295, 49,  194, 90,  210, 123,
                  271, 18,  276, 87,  177, 240, 276, 33,  155, 200, 51,  6,   212, 36,  149, 202, 48,  114, 58,  91,
                  83,  221, 175, 148, 278, 300, 284, 86,  191, 95,  77,  215, 113, 257, 153, 135, 217, 76,  85,  269,
                  126, 194, 199, 195, 20,  204, 194, 50,  220, 228, 90,  221, 256, 87,  157, 246, 74,  156, 9,   196,
                  16,  259, 234, 79,  31,  206, 148, 12,  223, 151, 96,  229, 165, 9,   144, 26,  255, 201, 33,  89,
                  145, 155, 1,   204, 37,  107, 80,  212, 88,  186, 254, 9,   158, 180, 24,  45,  158, 100, 52,  131,
                  71,  174, 229, 236, 296, 299, 184, 168, 41,  45,  76,  68,  122, 85,  292, 238, 293, 179, 143, 128,
                  47,  87,  267, 53,  187, 76,  292, 0,   160, 70,  172, 292, 9,   64,  156, 153, 26,  145, 196, 222 };
    int target = 202, ans = wiggleMaxLength(arr, LEN(arr));

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle);
    tcase_add_test(t, test_failed);
    tcase_add_test(t, test_own);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}