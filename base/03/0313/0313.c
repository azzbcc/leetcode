// 超级丑数 是一个正整数，并满足其所有质因数都出现在质数数组 primes 中。
//
// 给你一个整数 n 和一个整数数组 primes ，返回第 n 个 超级丑数 。
//
// 题目数据保证第 n 个 超级丑数 在 32-bit 带符号整数范围内。
//
//
//
// 示例 1：
//
//
// 输入：n = 12, primes = [2,7,13,19]
// 输出：32
// 解释：给定长度为 4 的质数数组 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
//
// 示例 2：
//
//
// 输入：n = 1, primes = [2,3,5]
// 输出：1
// 解释：1 不含质因数，因此它的所有质因数都在质数数组 primes = [2,3,5] 中。
//
//
//
//
//
//
// 提示：
//
//
// 1 <= n <= 106
// 1 <= primes.length <= 100
// 2 <= primes[i] <= 1000
// 题目数据 保证 primes[i] 是一个质数
// primes 中的所有值都 互不相同 ，且按 递增顺序 排列
//
//
//
//
// Related Topics 数组 哈希表 数学 动态规划 堆（优先队列）
// 👍 209 👎 0

typedef struct node {
    long val;
    struct node *next;
} node_t;
typedef struct {
    int base;
    node_t *head;
    node_t **tail;
} queue_t;
void queue_en(queue_t *q, long val) {
    node_t *node = malloc(sizeof(node_t));
    node->val = val, node->next = NULL;
    *q->tail = node, q->tail = &node->next;
}
void queue_de(queue_t *q) {
    node_t *node = q->head;
    if (!node) return;
    q->head = node->next;
    free(node);
}
void node_free(node_t *n) {
    if (n) node_free(n->next);
    free(n);
}
void swap(queue_t *a, queue_t *b) {
    for (queue_t tmp = *a; tmp.head != b->head; *a = *b, *b = tmp) {}
}
void heap_adjust(queue_t data[], int size, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < size && data[new_pos].head->val > data[new_pos + 1].head->val) new_pos += 1;
    if (new_pos < size && data[pos].head->val > data[new_pos].head->val) {
        swap(&data[pos], &data[new_pos]);
        heap_adjust(data, size, new_pos);
    }
}
int nthSuperUglyNumber(int n, int *primes, int size) {
    int ans;
    queue_t queues[size];
    for (int i = 0; i < size; ++i) {
        queues[i].base = primes[i], queues[i].head = NULL, queues[i].tail = &queues[i].head;
        queue_en(&queues[i], 1);
    }
    for (int i = 1; i < n; ++i) {
        ans = queues[0].head->val;
        for (int j = 0; j < size; ++j) {
            queue_en(&queues[j], 1L * queues[j].base * ans);
        }
        while (queues[0].head->val == ans) {
            queue_de(&queues[0]);
            heap_adjust(queues, size, 0);
        }
    }
    ans = queues[0].head->val;
    for (int i = 0; i < size; ++i) {
        node_free(queues[i].head);
    }
    return ans;
}
