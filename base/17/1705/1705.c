// 有一棵特殊的苹果树，一连 n 天，每天都可以长出若干个苹果。在第 i 天，树上会长出 apples[i] 个苹果，
// 这些苹果将会在 days[i] 天后（也就是说，第 i + days[i] 天时）腐烂，变得无法食用。也可能有那么几天，
// 树上不会长出新的苹果，此时用 apples[i] == 0 且 days[i] == 0 表示。
//
// 你打算每天 最多 吃一个苹果来保证营养均衡。注意，你可以在这 n 天之后继续吃苹果。
//
// 给你两个长度为 n 的整数数组 days 和 apples ，返回你可以吃掉的苹果的最大数目。
//
//
//
// 示例 1：
//
// 输入：apples = [1,2,3,5,2], days = [3,2,1,4,2]
// 输出：7
// 解释：你可以吃掉 7 个苹果：
// - 第一天，你吃掉第一天长出来的苹果。
// - 第二天，你吃掉一个第二天长出来的苹果。
// - 第三天，你吃掉一个第二天长出来的苹果。过了这一天，第三天长出来的苹果就已经腐烂了。
// - 第四天到第七天，你吃的都是第四天长出来的苹果。
//
//
// 示例 2：
//
// 输入：apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
// 输出：5
// 解释：你可以吃掉 5 个苹果：
// - 第一天到第三天，你吃的都是第一天长出来的苹果。
// - 第四天和第五天不吃苹果。
// - 第六天和第七天，你吃的都是第六天长出来的苹果。
//
//
//
//
// 提示：
//
//
// apples.length == n
// days.length == n
// 1 <= n <= 2 * 10⁴
// 0 <= apples[i], days[i] <= 2 * 10⁴
// 只有在 apples[i] = 0 时，days[i] = 0 才成立
//
// Related Topics 贪心 数组 堆（优先队列） 👍 95 👎 0

typedef struct {
    int apple, expire;
} node_t;
void swap(node_t *a, node_t *b) {
    for (node_t tmp = *a; tmp.apple != b->apple || tmp.expire != b->expire; *a = *b, *b = tmp) {}
}
typedef struct {
    int size;
    node_t *data;
} heap_t;
void heap_adjust(heap_t *heap, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < heap->size && heap->data[new_pos].expire > heap->data[new_pos + 1].expire) new_pos += 1;
    if (new_pos < heap->size && heap->data[pos].expire > heap->data[new_pos].expire) {
        swap(&heap->data[pos], &heap->data[new_pos]);
        heap_adjust(heap, new_pos);
    }
}
void heap_pop(heap_t *heap) {
    swap(&heap->data[0], &heap->data[--heap->size]);
    heap_adjust(heap, 0);
}
void heap_add(heap_t *heap, node_t val) {
    heap->data[heap->size] = val;
    for (int pos = heap->size++, parent; pos; pos = parent) {
        parent = (pos - 1) / 2;
        if (heap->data[parent].expire <= heap->data[pos].expire) break;
        swap(&heap->data[pos], &heap->data[parent]);
    }
}
int eatenApples(int *apples, int size, int *days, int daysSize) {
    int ans = 0;
    node_t memory[size];
    heap_t heap[1] = { 0, memory };
    for (int now = 0; now < size; ++now) {
        for (; heap->size && heap->data[0].expire <= now; heap_pop(heap)) {}
        if (apples[now]) heap_add(heap, (node_t) { apples[now], now + days[now] });
        if (heap->size && (ans += 1, !--heap->data[0].apple)) heap_pop(heap);
    }
    for (int now = size, c; heap->size;) {
        for (; heap->size && heap->data[0].expire <= now; heap_pop(heap)) {}
        if (!heap->size) break;
        c = fmin(heap->data[0].apple, heap->data[0].expire - now);
        now += c, ans += c, heap_pop(heap);
    }

    return ans;
}