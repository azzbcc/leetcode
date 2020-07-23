#include <check.h>

#include "add.c"
#include "sub.c"

START_TEST(test_add_01) {
    fail_unless(add(6, 2) == 8, "error, add(6, 2) != 8");
}

START_TEST(test_add_02) {
    fail_unless(add(563456345, 236236363) == 799692708, "error, add(563456345, 236236363) != 799692708");
}

START_TEST(test_sub_01) {
    fail_unless(sub(6, 2) == 4, "error, sub(6, 2) != 4");
}

START_TEST(test_sub_02) {
    fail_unless(sub(563456345, 236236363) == 327219982, "error, sub(6, 2) != 327219982");
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_add_01); // 测试用例加到测试集中
    tcase_add_test(t, test_add_02); // 测试用例加到测试集中
    tcase_add_test(t, test_sub_01); // 测试用例加到测试集中
    tcase_add_test(t, test_sub_02); // 测试用例加到测试集中
}