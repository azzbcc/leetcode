/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/8/28 下午6:08
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

static long getMicrotime() {
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_usec;
}

static void releaseHydrogen() {
    printf("%6lu: thread-%ld 'H'\n", getMicrotime(), ( long )pthread_self());
    usleep(100);
}

static void releaseOxygen() {
    printf("%6lu: thread-%ld 'O'\n", getMicrotime(), ( long )pthread_self());
    usleep(100);
}

#include "1117.c"

static void *othread(void *ptr) {
    printf("%6lu: thread-%ld would print 'O'\n", getMicrotime(), ( long )pthread_self());
    oxygen(ptr);
}
static void *hthread(void *ptr) {
    printf("%6lu: thread-%ld would print 'H'\n", getMicrotime(), ( long )pthread_self());
    hydrogen(ptr);
}

static void run(const char *str) {
    size_t len = strlen(str);
    pthread_t threads[len];
    H2O *o = h2oCreate();

    for (int i = 0; i < len; ++i) {
        usleep(1000);
        pthread_create(&threads[i], NULL, (str[i] == 'O' ? othread : hthread), o);
    }
    for (int i = 0; i < len; ++i) {
        pthread_join(threads[i], NULL);
    }

    puts("");
    h2oFree(o);
}

START_TEST(test_official_1) {
    run("HOH");
}
START_TEST(test_official_2) {
    run("OOHHHH");
}
START_TEST(test_rand) {
    const int n = 50;
    char str[3 * n + 1];
    str[3 * n] = '\0';
    for (int i = 0; i < 3 * n; ++i) {
        str[i] = i < n ? 'O' : 'H';
    }
    srand(time(NULL));
    for (int i = 3 * n - 1; i > 0; --i) {
        char tmp;
        long rand = random() % i;
        tmp = str[i], str[i] = str[rand], str[rand] = tmp;
    }
    run(str);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_rand);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
}