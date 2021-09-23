#include <check.h>

extern const char *program;
extern void tcase_complete(TCase *t);

static enum fork_status default_fork_status = CK_NOFORK;

void set_execute_timeout(TCase *tCase, double timeout) {
#ifndef ENABLE_MEMORY_CHECK
    default_fork_status = CK_FORK;
    tcase_set_timeout(tCase, timeout);
#endif
}

Suite *make_suite(void) {
    Suite *suite = suite_create(program);
    TCase *tCase = tcase_create(program);

    // 添加测试用例
    suite_add_tcase(suite, tCase);

    tcase_complete(tCase);

    return suite;
}

int main(void) {
    // 将Suite加入到SRunner
    SRunner *sr = srunner_create(make_suite());

    // 设置执行模式
    srunner_set_fork_status(sr, default_fork_status);

    // 执行所有测试用例
    srunner_run_all(sr, CK_NORMAL);

    // 运行所有测试用例
    int n = srunner_ntests_failed(sr);

    srunner_free(sr);

    return n;
}