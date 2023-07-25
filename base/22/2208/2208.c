// 给你一个正整数数组 nums 。每一次操作中，你可以从 nums 中选择 任意 一个数并将它减小到 恰好 一半。
// （注意，在后续操作中你可以对减半过的数继续执行操作）
//
// 请你返回将 nums 数组和 至少 减少一半的 最少 操作数。
//
//
//
// 示例 1：
//
// 输入：nums = [5,19,8,1]
// 输出：3
// 解释：初始 nums 的和为 5 + 19 + 8 + 1 = 33 。
// 以下是将数组和减少至少一半的一种方法：
// 选择数字 19 并减小为 9.5 。
// 选择数字 9.5 并减小为 4.75 。
// 选择数字 8 并减小为 4 。
// 最终数组为 [5, 4.75, 4, 1] ，和为 5 + 4.75 + 4 + 1 = 14.75 。
// nums 的和减小了 33 - 14.75 = 18.25 ，减小的部分超过了初始数组和的一半，18.25 >= 33/2 = 16.5 。
// 我们需要 3 个操作实现题目要求，所以返回 3 。
// 可以证明，无法通过少于 3 个操作使数组和减少至少一半。
//
//
// 示例 2：
//
// 输入：nums = [3,8,20]
// 输出：3
// 解释：初始 nums 的和为 3 + 8 + 20 = 31 。
// 以下是将数组和减少至少一半的一种方法：
// 选择数字 20 并减小为 10 。
// 选择数字 10 并减小为 5 。
// 选择数字 3 并减小为 1.5 。
// 最终数组为 [1.5, 8, 5] ，和为 1.5 + 8 + 5 = 14.5 。
// nums 的和减小了 31 - 14.5 = 16.5 ，减小的部分超过了初始数组和的一半， 16.5 >= 31/2 = 16.5 。
// 我们需要 3 个操作实现题目要求，所以返回 3 。
// 可以证明，无法通过少于 3 个操作使数组和减少至少一半。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 10⁵
// 1 <= nums[i] <= 10⁷
//
//
// Related Topics 贪心 数组 堆（优先队列） 👍 51 👎 0

typedef struct {
    long a, b;
} fact_t;
void swap(fact_t *a, fact_t *b) {
    for (fact_t tmp = *a; tmp.a != b->a || tmp.b != b->b; *a = *b, *b = tmp) {}
}
bool cmp(fact_t a, fact_t b) {
    return a.a * b.b < b.a * a.b;
}
void add(fact_t *a, fact_t b) {
    if (a->b < b.b) {
        a->a *= b.b / a->b, a->b = b.b;
    } else {
        b.a *= a->b / b.b, b.b = a->b;
    }
    a->a += b.a;
}
void shift(fact_t *a) {
    if (a->a % 2) {
        a->b *= 2;
    } else {
        a->a /= 2;
    }
}
void heap_adjust(fact_t data[], int size, int pos) {
    int new_pos = pos * 2 + 1;
    if (new_pos + 1 < size && cmp(data[new_pos], data[new_pos + 1])) new_pos += 1;
    if (new_pos < size && cmp(data[pos], data[new_pos])) {
        swap(&data[pos], &data[new_pos]);
        heap_adjust(data, size, new_pos);
    }
}
int halveArray(int *nums, int size) {
    int ans = 0;
    fact_t nodes[size], total = { .b = 1 }, now = { .b = 1 };
    for (int i = 0; i < size; ++i) {
        total.a += nums[i];
        nodes[i] = (fact_t) { nums[i], 1 };
    }
    for (int i = size / 2 - 1; i >= 0; heap_adjust(nodes, size, i--)) {}
    for (shift(&total); cmp(now, total); ++ans) {
        shift(&nodes[0]);
        add(&now, nodes[0]);
        heap_adjust(nodes, size, 0);
    }
    return ans;
}