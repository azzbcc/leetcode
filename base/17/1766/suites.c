/**
 * suites.c
 * Copyright(c) 2021 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2021/2/23 下午13:32
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1766.c"

START_TEST(test_official_1) {
    int nums[]   = { 2, 3, 3, 2 };
    int target[] = { -1, 0, 0, 1 };
    int *edges[] = { (int[]) { 0, 1 }, (int[]) { 1, 2 }, (int[]) { 1, 3 } };
    int len, *ans = getCoprimes(nums, LEN(nums), edges, LEN(edges), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_official_2) {
    int nums[]   = { 5, 6, 10, 2, 3, 6, 15 };
    int target[] = { -1, 0, -1, 0, 0, 0, -1 };
    int *edges[] = { (int[]) { 0, 1 }, (int[]) { 0, 2 }, (int[]) { 1, 3 },
                     (int[]) { 1, 4 }, (int[]) { 2, 5 }, (int[]) { 2, 6 } };
    int len, *ans = getCoprimes(nums, LEN(nums), edges, LEN(edges), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_fail_1) {
    int nums[]   = { 9,  16, 30, 23, 33, 35, 9,  47, 39, 46, 16, 38, 5,  49, 21, 44, 17, 1,  6,  37, 49, 15, 23, 46,
                   38, 9,  27, 3,  24, 1,  14, 17, 12, 23, 43, 38, 12, 4,  8,  17, 11, 18, 26, 22, 49, 14, 9 };
    int target[] = { -1, 21, 17, 43, 10, 42, 7,  13, 29, 44, 17, 31, 39, 10, 10, 29, 32, 0,  40, 23, 12, 39, 12, 40,
                     25, 35, 15, 38, 40, 40, 17, 24, 5,  1,  19, 14, 17, 21, 25, 24, 14, 17, 40, 25, 37, 17, 10 };
    int *edges[] = { (int[]) { 17, 0 },  (int[]) { 30, 17 }, (int[]) { 41, 30 }, (int[]) { 10, 30 }, (int[]) { 13, 10 },
                     (int[]) { 7, 13 },  (int[]) { 6, 7 },   (int[]) { 45, 10 }, (int[]) { 2, 10 },  (int[]) { 14, 2 },
                     (int[]) { 40, 14 }, (int[]) { 28, 40 }, (int[]) { 29, 40 }, (int[]) { 8, 29 },  (int[]) { 15, 29 },
                     (int[]) { 26, 15 }, (int[]) { 23, 40 }, (int[]) { 19, 23 }, (int[]) { 34, 19 }, (int[]) { 18, 23 },
                     (int[]) { 42, 18 }, (int[]) { 5, 42 },  (int[]) { 32, 5 },  (int[]) { 16, 32 }, (int[]) { 35, 14 },
                     (int[]) { 25, 35 }, (int[]) { 43, 25 }, (int[]) { 3, 43 },  (int[]) { 36, 25 }, (int[]) { 38, 36 },
                     (int[]) { 27, 38 }, (int[]) { 24, 36 }, (int[]) { 31, 24 }, (int[]) { 11, 31 }, (int[]) { 39, 24 },
                     (int[]) { 12, 39 }, (int[]) { 20, 12 }, (int[]) { 22, 12 }, (int[]) { 21, 39 }, (int[]) { 1, 21 },
                     (int[]) { 33, 1 },  (int[]) { 37, 1 },  (int[]) { 44, 37 }, (int[]) { 9, 44 },  (int[]) { 46, 2 },
                     (int[]) { 4, 46 } };
    int len, *ans = getCoprimes(nums, LEN(nums), edges, LEN(edges), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

START_TEST(test_fail_2) {
    int nums[]   = { 36, 49, 26, 50, 23, 41, 1,  33, 7,  8,  26, 14, 43, 49, 21, 36, 2,  11, 33, 8,  34, 20,
                   11, 12, 39, 46, 4,  47, 31, 33, 38, 39, 13, 14, 1,  5,  4,  44, 3,  13, 25, 34, 2,  40,
                   35, 4,  13, 37, 12, 26, 27, 5,  7,  1,  42, 44, 41, 43, 43, 8,  50, 8,  44, 40, 11, 1,
                   17, 34, 25, 8,  14, 9,  19, 6,  44, 38, 49, 50, 27, 50, 25, 10, 1,  41, 30, 5,  26, 38,
                   6,  48, 40, 13, 11, 44, 44, 14, 48, 16, 3,  24, 4,  26, 36, 7,  35, 50, 34, 32 };
    int target[] = { -1, 90, 13, 98, 70, 59, 10,  81, 61, 35, 58, 7,  67, 24, 90, 85,  18,  21, 107, 46,  7,  47,
                     31, 47, 79, 46, 7,  63, 26,  9,  39, 37, 1,  24, 30, 23, 56, -1,  90,  37, 45,  53,  98, 47,
                     92, 56, 13, 65, 46, 56, 107, 48, 90, 79, 12, 91, 10, 38, 37, 53,  47,  46, 46,  7,   99, 19,
                     75, 98, 53, 39, 24, 39, 67,  35, 46, 14, 92, 46, 59, 12, 93, 46,  104, 44, 46,  107, 13, 46,
                     47, 46, 46, 64, 20, 46, -1,  46, 65, 46, 39, -1, 46, 56, 22, 105, 93,  5,  46,  98 };
    int *edges[] = {
        (int[]) { 99, 0 },   (int[]) { 64, 99 },  (int[]) { 91, 64 },  (int[]) { 55, 91 },   (int[]) { 94, 0 },
        (int[]) { 37, 94 },  (int[]) { 58, 37 },  (int[]) { 10, 58 },  (int[]) { 6, 10 },    (int[]) { 56, 10 },
        (int[]) { 45, 56 },  (int[]) { 36, 45 },  (int[]) { 40, 45 },  (int[]) { 49, 56 },   (int[]) { 101, 49 },
        (int[]) { 39, 37 },  (int[]) { 69, 39 },  (int[]) { 30, 69 },  (int[]) { 34, 30 },   (int[]) { 71, 39 },
        (int[]) { 98, 39 },  (int[]) { 31, 98 },  (int[]) { 22, 31 },  (int[]) { 102, 22 },  (int[]) { 3, 98 },
        (int[]) { 107, 3 },  (int[]) { 50, 107 }, (int[]) { 18, 50 },  (int[]) { 16, 18 },   (int[]) { 85, 107 },
        (int[]) { 15, 85 },  (int[]) { 67, 107 }, (int[]) { 42, 67 },  (int[]) { 72, 67 },   (int[]) { 12, 67 },
        (int[]) { 79, 12 },  (int[]) { 53, 79 },  (int[]) { 41, 53 },  (int[]) { 68, 53 },   (int[]) { 59, 53 },
        (int[]) { 78, 59 },  (int[]) { 5, 59 },   (int[]) { 105, 5 },  (int[]) { 103, 105 }, (int[]) { 24, 79 },
        (int[]) { 70, 24 },  (int[]) { 4, 70 },   (int[]) { 33, 70 },  (int[]) { 54, 70 },   (int[]) { 13, 70 },
        (int[]) { 46, 13 },  (int[]) { 74, 46 },  (int[]) { 93, 74 },  (int[]) { 90, 93 },   (int[]) { 1, 90 },
        (int[]) { 32, 1 },   (int[]) { 52, 1 },   (int[]) { 38, 90 },  (int[]) { 57, 38 },   (int[]) { 95, 90 },
        (int[]) { 14, 95 },  (int[]) { 75, 14 },  (int[]) { 66, 75 },  (int[]) { 97, 95 },   (int[]) { 2, 97 },
        (int[]) { 86, 97 },  (int[]) { 25, 97 },  (int[]) { 100, 25 }, (int[]) { 61, 100 },  (int[]) { 8, 61 },
        (int[]) { 104, 93 }, (int[]) { 80, 104 }, (int[]) { 82, 104 }, (int[]) { 19, 74 },   (int[]) { 81, 19 },
        (int[]) { 62, 81 },  (int[]) { 87, 81 },  (int[]) { 48, 87 },  (int[]) { 77, 48 },   (int[]) { 51, 77 },
        (int[]) { 7, 81 },   (int[]) { 63, 7 },   (int[]) { 27, 63 },  (int[]) { 26, 63 },   (int[]) { 28, 26 },
        (int[]) { 84, 7 },   (int[]) { 11, 84 },  (int[]) { 20, 7 },   (int[]) { 89, 20 },   (int[]) { 92, 20 },
        (int[]) { 76, 92 },  (int[]) { 44, 92 },  (int[]) { 83, 44 },  (int[]) { 65, 19 },   (int[]) { 47, 65 },
        (int[]) { 60, 47 },  (int[]) { 23, 60 },  (int[]) { 43, 23 },  (int[]) { 21, 43 },   (int[]) { 17, 21 },
        (int[]) { 35, 23 },  (int[]) { 9, 35 },   (int[]) { 29, 9 },   (int[]) { 73, 29 },   (int[]) { 88, 60 },
        (int[]) { 96, 65 },  (int[]) { 106, 19 }
    };
    int len, *ans = getCoprimes(nums, LEN(nums), edges, LEN(edges), NULL, &len);
    ck_assert_int_eq(len, LEN(target));
    ck_assert_mem_eq(ans, target, sizeof(target));
    free(ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_fail_1);
    tcase_add_test(t, test_fail_2);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}