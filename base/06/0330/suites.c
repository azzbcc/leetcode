/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/12/29 上午11:46
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0330.c"

START_TEST(test_official_1) {
    int arr[] = { 1, 3 }, n = 6;
    int target = 1, ans = minPatches(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_2) {
    int arr[] = { 1, 5, 10 }, n = 20;
    int target = 2, ans = minPatches(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_official_3) {
    int arr[] = { 1, 2, 2 }, n = 5;
    int target = 0, ans = minPatches(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_1) {
    int arr[] = { 2, 4, 14, 18, 20, 25, 25, 35, 73, 94 }, n = 42;
    int target = 2, ans = minPatches(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_failed_2) {
    int arr[] = { 1, 2, 16, 19, 31, 35, 36, 64, 64, 67, 69, 71, 73, 74, 76, 79, 80, 91, 95, 96, 97 }, n = 8;
    int target = 2, ans = minPatches(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle_1) {
    int arr[] = { 1, 2, 31, 33 }, n = 2147483647;
    int target = 28, ans = minPatches(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

START_TEST(test_tle_2) {
    int arr[] = {
        1,   1,   3,   3,   4,   5,   6,   7,   7,   8,   8,   8,   9,   10,  11,  12,  13,  13,  14,  15,  18,  18,
        20,  20,  21,  23,  23,  26,  27,  27,  28,  29,  31,  32,  33,  37,  38,  42,  42,  42,  43,  43,  43,  43,
        44,  44,  45,  45,  45,  45,  46,  46,  47,  48,  50,  50,  51,  51,  51,  53,  55,  55,  55,  56,  56,  57,
        58,  58,  59,  59,  60,  63,  66,  67,  68,  68,  69,  71,  72,  73,  77,  78,  78,  81,  82,  82,  83,  84,
        84,  86,  88,  90,  92,  92,  93,  94,  94,  96,  97,  97,  98,  99,  99,  99,  100, 101, 104, 105, 107, 107,
        107, 108, 108, 109, 111, 113, 115, 118, 119, 119, 121, 122, 122, 124, 124, 124, 125, 126, 127, 127, 128, 129,
        131, 131, 132, 134, 137, 138, 138, 139, 139, 140, 141, 145, 150, 151, 152, 153, 154, 156, 156, 156, 157, 157,
        160, 161, 161, 161, 162, 163, 165, 165, 167, 167, 171, 172, 173, 174, 175, 176, 178, 181, 181, 183, 184, 184,
        188, 191, 191, 192, 193, 194, 196, 196, 196, 197, 200, 200, 202, 202, 205, 205, 206, 206, 209, 209, 212, 212,
        213, 216, 218, 218, 219, 220, 221, 223, 225, 226, 226, 227, 228, 229, 229, 230, 230, 233, 233, 233, 235, 240,
        242, 242, 243, 244, 246, 247, 247, 247, 250, 251, 253, 254, 256, 256, 257, 259, 259, 260, 260, 262, 263, 263,
        263, 266, 270, 271, 272, 273, 275, 276, 277, 277, 279, 280, 281, 283, 284, 284, 285, 286, 286, 286, 287, 287,
        289, 290, 290, 292, 292, 293, 293, 294, 295, 298, 300, 300, 302, 304, 304, 305, 305, 308, 309, 310, 312, 312,
        313, 314, 314, 317, 318, 318, 321, 323, 326, 326, 328, 332, 332, 333, 333, 333, 333, 334, 336, 336, 336, 339,
        340, 340, 341, 343, 344, 345, 346, 348, 349, 349, 350, 351, 352, 352, 352, 354, 354, 355, 356, 356, 357, 359,
        361, 362, 363, 363, 364, 364, 365, 367, 367, 368, 369, 370, 370, 370, 371, 373, 377, 378, 378, 378, 379, 380,
        382, 383, 383, 385, 387, 387, 387, 389, 389, 393, 393, 395, 395, 396, 396, 397, 397, 397, 397, 397, 401, 401,
        402, 403, 404, 405, 406, 406, 406, 407, 407, 408, 410, 414, 417, 421, 421, 422, 424, 425, 428, 430, 431, 432,
        433, 434, 435, 438, 438, 440, 441, 441, 444, 444, 444, 444, 446, 448, 448, 449, 449, 450, 451, 452, 454, 454,
        454, 455, 459, 460, 461, 462, 462, 463, 465, 465, 468, 470, 470, 472, 472, 472, 473, 474, 474, 476, 477, 478,
        480, 484, 484, 485, 485, 487, 492, 494, 494, 494, 494, 494, 495, 495, 498, 498, 499, 499, 499, 502, 504, 504,
        504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 515, 517, 517, 518, 519, 519, 520, 521, 521, 521, 522, 523,
        524, 525, 528, 530, 531, 532, 532, 532, 535, 537, 538, 539, 541, 544, 547, 548, 550, 550, 553, 553, 554, 554,
        557, 558, 560, 560, 563, 564, 567, 567, 567, 567, 568, 570, 572, 573, 574, 575, 575, 576, 576, 576, 578, 579,
        580, 581, 581, 581, 582, 583, 585, 586, 586, 587, 588, 588, 589, 592, 592, 593, 594, 596, 596, 599, 601, 601,
        602, 602, 602, 604, 606, 606, 607, 608, 609, 609, 610, 610, 610, 610, 611, 612, 613, 615, 615, 618, 619, 620,
        621, 622, 622, 622, 623, 624, 625, 626, 626, 627, 627, 629, 630, 631, 632, 632, 633, 633, 634, 638, 638, 640,
        642, 642, 643, 645, 645, 648, 649, 652, 652, 652, 652, 658, 658, 663, 664, 664, 665, 668, 669, 669, 672, 672,
        672, 673, 673, 675, 675, 676, 678, 678, 679, 679, 681, 682, 683, 684, 685, 686, 690, 692, 693, 693, 695, 696,
        697, 698, 698, 701, 702, 704, 705, 705, 705, 706, 707, 708, 710, 710, 713, 714, 716, 716, 717, 717, 717, 719,
        719, 719, 720, 721, 722, 722, 723, 723, 723, 725, 725, 728, 731, 735, 739, 739, 739, 741, 742, 744, 745, 745,
        748, 749, 749, 749, 750, 753, 753, 754, 755, 756, 757, 758, 759, 759, 760, 762, 762, 765, 766, 766, 769, 770,
        770, 770, 771, 771, 772, 774, 775, 776, 778, 780, 780, 780, 781, 783, 783, 784, 784, 784, 784, 785, 785, 787,
        788, 788, 792, 794, 795, 796, 797, 797, 798, 798, 798, 798, 799, 800, 800, 800, 801, 805, 806, 807, 807, 808,
        809, 810, 811, 811, 813, 813, 814, 816, 817, 818, 819, 821, 821, 822, 823, 824, 824, 825, 831, 832, 834, 837,
        840, 840, 842, 844, 847, 848, 851, 853, 853, 854, 854, 856, 858, 859, 860, 862, 862, 863, 864, 864, 865, 865,
        866, 866, 867, 867, 869, 871, 873, 874, 874, 875, 876, 877, 879, 883, 884, 886, 888, 889, 890, 892, 894, 894,
        895, 898, 900, 902, 904, 905, 905, 906, 906, 906, 907, 910, 910, 913, 913, 914, 915, 915, 916, 916, 916, 917,
        917, 919, 920, 921, 922, 922, 924, 924, 926, 928, 930, 930, 930, 931, 932, 933, 934, 936, 938, 939, 940, 940,
        941, 943, 944, 944, 945, 946, 947, 950, 951, 954, 955, 957, 960, 961, 963, 963, 963, 966, 967, 967, 968, 971,
        973, 973, 974, 975, 977, 979, 979, 981, 982, 983, 985, 987, 987, 990, 991, 993, 993, 994, 995, 997
    };
    int n = 656602, target = 1, ans = minPatches(arr, LEN(arr), n);

    ck_assert_int_eq(ans, target);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle_2);
    tcase_add_test(t, test_tle_1);
    tcase_add_test(t, test_failed_2);
    tcase_add_test(t, test_failed_1);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}