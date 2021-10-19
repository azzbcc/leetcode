// 有 N 名工人。 第 i 名工人的工作质量为 quality[i] ，其最低期望工资为 wage[i] 。
//
// 现在我们想雇佣 K 名工人组成一个工资组。在雇佣 一组 K 名工人时，我们必须按照下述规则向他们支付工资：
//
//
// 对工资组中的每名工人，应当按其工作质量与同组其他工人的工作质量的比例来支付工资。
// 工资组中的每名工人至少应当得到他们的最低期望工资。
//
//
// 返回组成一个满足上述条件的工资组至少需要多少钱。
//
//
//
//
//
//
// 示例 1：
//
// 输入： quality = [10,20,5], wage = [70,50,30], K = 2
// 输出： 105.00000
// 解释： 我们向 0 号工人支付 70，向 2 号工人支付 35。
//
// 示例 2：
//
// 输入： quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
// 输出： 30.66667
// 解释： 我们向 0 号工人支付 4，向 2 号和 3 号分别支付 13.33333。
//
//
//
// 提示：
//
//
// 1 <= K <= N <= 10000，其中 N = quality.length = wage.length
// 1 <= quality[i] <= 10000
// 1 <= wage[i] <= 10000
// 与正确答案误差在 10^-5 之内的答案将被视为正确的。
//
// Related Topics 贪心 数组 排序 堆（优先队列） 👍 128 👎 0

typedef struct {
    double rate;
    int quality, wage;
} node_t;
typedef struct {
    int size;
    int data[];
} * heap_t;
int cmp(const void *a, const void *b) {
    node_t *pa = ( node_t * )a, *pb = ( node_t * )b;
    if (pa->rate > pb->rate) return 1;
    if (pa->rate < pb->rate) return -1;
    return 0;
}
void swap(int *a, int *b) {
    for (int tmp = *a; tmp != *b; *a = *b, *b = tmp) {}
}
void heap_adjust(heap_t heap, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < heap->size && heap->data[new_pos] < heap->data[new_pos + 1]) new_pos += 1;
    if (new_pos < heap->size && heap->data[pos] < heap->data[new_pos]) {
        swap(&heap->data[pos], &heap->data[new_pos]);
        heap_adjust(heap, new_pos);
    }
}
void heap_add(heap_t heap, int val) {
    heap->data[heap->size] = val;
    for (int pos = heap->size++, parent; pos; pos = parent) {
        parent = (pos - 1) / 2;
        if (heap->data[parent] >= heap->data[pos]) break;
        swap(&heap->data[pos], &heap->data[parent]);
    }
}
double mincostToHireWorkers(int *quality, int size, int *wage, int wageSize, int k) {
    int sum = 0;
    node_t nodes[size];
    heap_t heap = malloc(sizeof(*heap) + k * sizeof(node_t *));

    for (int i = 0; i < size; ++i) {
        nodes[i] = (node_t) { 1. * wage[i] / quality[i], quality[i], wage[i] };
    }

    heap->size = 0, qsort(nodes, size, sizeof(node_t), cmp);
    for (int i = 0; i < k; ++i) {
        sum += nodes[i].quality;
        heap_add(heap, nodes[i].quality);
    }
    double ans = nodes[k - 1].rate * sum;
    for (int i = k; i < size; ++i) {
        if (nodes[i].quality > heap->data[0]) continue;
        sum += nodes[i].quality - heap->data[0];

        heap->data[0] = nodes[i].quality;
        heap_adjust(heap, 0);

        ans = fmin(ans, sum * nodes[i].rate);
    }
    free(heap);
    return ans;
}