#include <check.h>

extern void tcase_complete(TCase *t);

Suite *make_suite(void) {
    Suite *suite = suite_create(PROGRAM);
    TCase *tCase = tcase_create(PROGRAM);

    // 添加测试用例
    suite_add_tcase(suite, tCase);

    tcase_complete(tCase);

    return suite;
}

int main(void) {
    // 将Suite加入到SRunner
    SRunner *sr = srunner_create(make_suite());

    // 执行所有测试用例
    srunner_run_all(sr, CK_NORMAL);

    // 运行所有测试用例
    int n = srunner_ntests_failed(sr);

    srunner_free(sr);

    return n;
}