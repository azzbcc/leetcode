// 给你两个下标从 0 开始的数组 nums1 和 nums2 ，和一个二维数组 queries 表示一些操作。总共有 3 种类型的操作：
//
//
// 操作类型 1 为 queries[i] = [1, l, r] 。你需要将 nums1 从下标 l 到下标 r 的所有 0 反转成 1 或将 1 反转成0 。
//  l 和 r 下标都从 0 开始。
// 操作类型 2 为 queries[i] = [2, p, 0] 。对于 0 <= i < n 中的所有下标，令 nums2[i] = nums2[i] + nums1[i] * p 。
// 操作类型 3 为 queries[i] = [3, 0, 0] 。求 nums2 中所有元素的和。
//
//
// 请你返回一个数组，包含所有第三种操作类型的答案。
//
//
//
// 示例 1：
//
//
// 输入：nums1 = [1,0,1], nums2 = [0,0,0], queries = [[1,1,1],[2,1,0],[3,0,0]]
// 输出：[3]
// 解释：第一个操作后 nums1 变为 [1,1,1] 。第二个操作后，nums2 变成 [1,1,1] ，所以第三个操作的答案为 3 。所以返回 [3] 。
//
//
//
// 示例 2：
//
//
// 输入：nums1 = [1], nums2 = [5], queries = [[2,0,0],[3,0,0]]
// 输出：[5]
// 解释：第一个操作后，nums2 保持不变为 [5] ，所以第二个操作的答案是 5 。所以返回 [5] 。
//
//
//
//
// 提示：
//
//
// 1 <= nums1.length,nums2.length <= 10⁵
// nums1.length = nums2.length
// 1 <= queries.length <= 10⁵
// queries[i].length = 3
// 0 <= l <= r <= nums1.length - 1
// 0 <= p <= 10⁶
// 0 <= nums1[i] <= 1
// 0 <= nums2[i] <= 10⁹
//
//
// Related Topics 线段树 数组 👍 51 👎 0

typedef struct {
    bool lazy;
    int l, r, sum;
} seg_tree_t;
void build(seg_tree_t t[], int idx, int l, int r, int arr[]) {
    t[idx] = (seg_tree_t) { .l = l, .r = r };
    if (l == r) {
        t[idx].sum = arr[l];
    } else {
        int mid = (l + r) / 2;
        build(t, idx * 2 + 1, l, mid + 0, arr);
        build(t, idx * 2 + 2, mid + 1, r, arr);
        t[idx].sum = t[2 * idx + 1].sum + t[2 * idx + 2].sum;
    }
}
void pushdown(seg_tree_t t[], int idx) {
    if (!t[idx].lazy) return;
    t[idx].lazy = false;

    t[2 * idx + 1].lazy = !t[2 * idx + 1].lazy;
    t[2 * idx + 2].lazy = !t[2 * idx + 2].lazy;

    t[2 * idx + 1].sum = t[2 * idx + 1].r - t[2 * idx + 1].l + 1 - t[2 * idx + 1].sum;
    t[2 * idx + 2].sum = t[2 * idx + 2].r - t[2 * idx + 2].l + 1 - t[2 * idx + 2].sum;
}
void update(seg_tree_t t[], int idx, int l, int r) {
    if (t[idx].l >= l && t[idx].r <= r) {
        t[idx].sum  = (t[idx].r - t[idx].l + 1) - t[idx].sum;
        t[idx].lazy = !t[idx].lazy;
    } else {
        pushdown(t, idx);
        if (t[2 * idx + 1].r >= l) update(t, 2 * idx + 1, l, r);
        if (t[2 * idx + 2].l <= r) update(t, 2 * idx + 2, l, r);
        t[idx].sum = t[2 * idx + 1].sum + t[2 * idx + 2].sum;
    }
}
long long query(seg_tree_t t[], int idx, int l, int r) {
    if (t[idx].l >= l && t[idx].r <= r) return t[idx].sum;
    if (t[idx].r < l || t[idx].l > r) return 0;

    pushdown(t, idx);
    long long res = 0;
    if (t[2 * idx + 1].l <= r) res += query(t, 2 * idx + 1, l, r);
    if (t[2 * idx + 2].r >= l) res += query(t, 2 * idx + 2, l, r);
    return res;
}
long long *handleQuery(int *nums1, int numsSize, int *nums2, int nums2Size, int **queries, int size, int *colSize,
                       int *returnSize) {
    seg_tree_t tree[numsSize * 4];
    long long sum = 0L, help[size], len = 0;

    build(tree, 0, 0, numsSize - 1, nums1);
    for (int i = 0; i < numsSize; sum += nums2[i++]) {}
    for (int i = 0; i < size; ++i) {
        if (queries[i][0] == 1) {
            update(tree, 0, queries[i][1], queries[i][2]);
        } else if (queries[i][0] == 2) {
            sum += query(tree, 0, 0, numsSize - 1) * queries[i][1];
        } else {
            help[len++] = sum;
        }
    }

    long long *ans = malloc((*returnSize = len) * sizeof(long long));
    memcpy(ans, help, len * sizeof(long long));
    return ans;
}
