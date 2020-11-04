// 编写一个程序，找出第 n 个丑数。
//
// 丑数就是质因数只包含 2, 3, 5 的正整数。
//
// 示例:
//
// 输入: n = 10
// 输出: 12
// 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
//
// 说明:
//
//
// 1 是丑数。
// n 不超过1690。
//
// Related Topics 堆 数学 动态规划
// 👍 417 👎 0

#define MAXN 1690

typedef struct {
    long data[MAXN + 1];
    int front, rear;
} queue_t;

long queue_front(queue_t *q) {
    return q->data[q->front];
}
void queue_push(queue_t *q, long val) {
    q->data[q->rear++] = val;
}
void queue_pop(queue_t *q) {
    q->front++;
}
long min(long a, long b, long c) {
    if (a > b) a = b;
    if (a > c) a = c;
    return a;
}
int nthUglyNumber(int n) {
    long ans;
    queue_t q2 = { 0 }, q3 = { 0 }, q5 = { 0 };

    queue_push(&q2, 1), queue_push(&q3, 1), queue_push(&q5, 1);
    while (n--) {
        ans = min(queue_front(&q2), queue_front(&q3), queue_front(&q5));

        if (ans == queue_front(&q2)) queue_pop(&q2);
        if (ans == queue_front(&q3)) queue_pop(&q3);
        if (ans == queue_front(&q5)) queue_pop(&q5);
        queue_push(&q2, ans * 2), queue_push(&q3, ans * 3), queue_push(&q5, ans * 5);
    }

    return ans;
}