/**
 * suites.c
 * Copyright(c) 2023 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2023/9/23 11:23
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "1993.c"

START_TEST(test_official) {
    int parent[]      = { -1, 0, 0, 1, 1, 2, 2 };
    LockingTree *tree = lockingTreeCreate(parent, LEN(parent));
    ck_assert_ptr_nonnull(tree);

    char *commands[] = { "lock", "unlock", "unlock", "lock", "upgrade", "lock" };
    int *argv[]      = { (int[]) { 2, 2 }, (int[]) { 2, 3 }, (int[]) { 2, 2 },
                         (int[]) { 4, 5 }, (int[]) { 0, 1 }, (int[]) { 0, 1 } };
    bool ans, target[] = { true, false, true, true, true, false };
    for (int i = 0; i < LEN(commands); ++i) {
        if (!strcmp(commands[i], "lock")) {
            ans = lockingTreeLock(tree, argv[i][0], argv[i][1]);
        } else if (!strcmp(commands[i], "unlock")) {
            ans = lockingTreeUnlock(tree, argv[i][0], argv[i][1]);
        } else if (!strcmp(commands[i], "upgrade")) {
            ans = lockingTreeUpgrade(tree, argv[i][0], argv[i][1]);
        } else {
            ck_abort_msg("error command: %s\n", commands[i]);
        }
        ck_assert(ans == target[i]);
    }
    lockingTreeFree(tree);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_official);
}