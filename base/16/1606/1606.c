// 你有 k 个服务器，编号为 0 到 k-1 ，它们可以同时处理多个请求组。每个服务器有无穷的计算能力但是不能同时处理超过一个请求
// 。请求分配到服务器的规则如下：
//
//
// 第 i （序号从 0 开始）个请求到达。如果所有服务器都已被占据，那么该请求被舍弃（完全不处理）。如果第 (i % k)
// 个服务器空闲， 那么对应服务器会处理该请求。否则，将请求安排给下一个空闲的服务器（服务器构成一个环，必要的话可能从第
// 0个服务器开始继续找下一个空闲的服务器） 比方说，如果第 i个服务器在忙，那么会查看第 (i+1) 个服务器，第 (i+2)
// 个服务器等等。
//
//
// 给你一个 严格递增 的正整数数组 arrival ，表示第 i 个任务的到达时间，和另一个数组 load ，
// 其中 load[i] 表示第 i 个请求的工作量（也就是服务器完成它所需要的时间）。你的任务是找到最繁忙的服务器 。
// 最繁忙定义为一个服务器处理的请求数是所有服务器里最多的。
//
// 请你返回包含所有 最繁忙服务器 序号的列表，你可以以任意顺序返回这个列表。
//
//
//
// 示例 1：
//
//
//
//
// 输入：k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3]
// 输出：[1]
// 解释：
// 所有服务器一开始都是空闲的。
// 前 3 个请求分别由前 3 台服务器依次处理。
// 请求 3 进来的时候，服务器 0
// 被占据，所以它被安排到下一台空闲的服务器，也就是服务器 1 。 请求 4
// 进来的时候，由于所有服务器都被占据，该请求被舍弃。 服务器 0 和 2
// 分别都处理了一个请求，服务器 1 处理了两个请求。所以服务器 1 是最忙的服务器。
//
//
// 示例 2：
//
//
// 输入：k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
// 输出：[0]
// 解释：
// 前 3 个请求分别被前 3 个服务器处理。
// 请求 3 进来，由于服务器 0 空闲，它被服务器 0 处理。
// 服务器 0 处理了两个请求，服务器 1 和 2 分别处理了一个请求。所以服务器 0
// 是最忙的服务器。
//
//
// 示例 3：
//
//
// 输入：k = 3, arrival = [1,2,3], load = [10,12,11]
// 输出：[0,1,2]
// 解释：每个服务器分别处理了一个请求，所以它们都是最忙的服务器。
//
//
// 示例 4：
//
//
// 输入：k = 3, arrival = [1,2,3,4,8,9,10], load = [5,2,10,3,1,2,2]
// 输出：[1]
//
//
// 示例 5：
//
//
// 输入：k = 1, arrival = [1], load = [1]
// 输出：[0]
//
//
//
//
// 提示：
//
//
// 1 <= k <= 10⁵
// 1 <= arrival.length, load.length <= 10⁵
// arrival.length == load.length
// 1 <= arrival[i], load[i] <= 10⁹
// arrival 保证 严格递增 。
//
// Related Topics 贪心 数组 有序集合 堆（优先队列） 👍 99 👎 0

typedef struct {
    int time, index;
} data_t;
typedef struct {
    int size;
    data_t *data;
} heap_t;
void swap(data_t *a, data_t *b) {
    for (data_t tmp = *a; tmp.time != b->time || tmp.index != b->index; *a = *b, *b = tmp) {}
}
int comp(data_t *a, data_t *b) {
    return a->time - b->time;
}
void heap_adjust(heap_t *heap, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < heap->size && comp(&heap->data[new_pos], &heap->data[new_pos + 1]) > 0) new_pos += 1;
    if (new_pos < heap->size && comp(&heap->data[pos], &heap->data[new_pos]) > 0) {
        swap(&heap->data[pos], &heap->data[new_pos]);
        heap_adjust(heap, new_pos);
    }
}
void heap_add(heap_t *heap, data_t val) {
    heap->data[heap->size] = val;
    for (int pos = heap->size++, parent; pos; pos = parent) {
        parent = (pos - 1) / 2;
        if (comp(&heap->data[pos], &heap->data[parent]) >= 0) break;
        swap(&heap->data[pos], &heap->data[parent]);
    }
}
data_t heap_pop(heap_t *heap) {
    data_t ans    = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    heap_adjust(heap, 0);
    return ans;
}
int *busiestServers(int k, int *arrival, int size, int *load, int loadSize, int *returnSize) {
    int cs[k], max = 0, len = 0;
    int *ans = malloc(k * sizeof(int));
    data_t memory_k[k], memory_size[size];
    heap_t available[1] = { { k, memory_k } }, worker[1] = { { .data = memory_size } };

    memset(cs, 0, sizeof(cs));
    for (int i = 0; i < k; ++i) {
        available->data[i] = (data_t) { i };
    }
    for (int i = 0, start, cost, index; i < size; ++i) {
        for (start = arrival[i], cost = load[i]; worker->size && worker->data[0].time <= start;) {
            for (index = heap_pop(worker).index - i; index < 0; index += k) {}
            heap_add(available, (data_t) { i + index % k });
        }
        if (!available->size) continue;
        heap_add(worker, (data_t) { start + cost, index = heap_pop(available).time % k });
        if (++cs[index] < max) continue;
        if (cs[index] > max) max = cs[index], len = 0;
        ans[len++] = index;
    }

    *returnSize = len;
    return ans;
}
