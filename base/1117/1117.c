// 现在有两种线程，氧 oxygen 和氢 hydrogen，你的目标是组织这两种线程来产生水分子。
//
// 存在一个屏障（barrier）使得每个线程必须等候直到一个完整水分子能够被产生出来。
//
// 氢和氧线程会被分别给予 releaseHydrogen 和 releaseOxygen 方法来允许它们突破屏障。
//
// 这些线程应该三三成组突破屏障并能立即组合产生一个水分子。
//
// 你必须保证产生一个水分子所需线程的结合必须发生在下一个水分子产生之前。
//
// 换句话说:
//
//
// 如果一个氧线程到达屏障时没有氢线程到达，它必须等候直到两个氢线程到达。
// 如果一个氢线程到达屏障时没有其它线程到达，它必须等候直到一个氧线程和另一个氢线程到达。
//
//
// 书写满足这些限制条件的氢、氧线程同步代码。
//
//
//
// 示例 1:
//
// 输入: "HOH"
// 输出: "HHO"
// 解释: "HOH" 和 "OHH" 依然都是有效解。
//
//
// 示例 2:
//
// 输入: "OOHHHH"
// 输出: "HHOHHO"
// 解释: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" 和 "OH
// HOHH" 依然都是有效解。
//
//
//
//
// 提示：
//
//
// 输入字符串的总长将会是 3n, 1 ≤ n ≤ 50；
// 输入字符串中的 “H” 总数将会是 2n 。
// 输入字符串中的 “O” 总数将会是 n 。
//
// 👍 69 👎 0

typedef struct {
    int h, o;
    pthread_cond_t cond;
    pthread_mutex_t mutex;
} H2O;

H2O *h2oCreate() {
    H2O *o = calloc(1, sizeof(H2O));

    o->h = o->o = 0;
    pthread_cond_init(&o->cond, NULL);
    pthread_mutex_init(&o->mutex, NULL);

    return o;
}

void hydrogen(H2O *o) {
    pthread_mutex_lock(&o->mutex);
    while (o->h > o->o * 2) {
        pthread_cond_wait(&o->cond, &o->mutex);
    }
    o->h++;
    releaseHydrogen();
    pthread_cond_signal(&o->cond);
    pthread_mutex_unlock(&o->mutex);
}

void oxygen(H2O *o) {
    pthread_mutex_lock(&o->mutex);
    while (o->o > o->h / 2) {
        pthread_cond_wait(&o->cond, &o->mutex);
    }
    o->o++;
    releaseOxygen();
    pthread_cond_signal(&o->cond);
    pthread_mutex_unlock(&o->mutex);
}

void h2oFree(H2O *o) {
    pthread_cond_destroy(&o->cond);
    pthread_mutex_destroy(&o->mutex);

    free(o);
}
