// 在仅包含 0 和 1 的数组 A 中，一次 K 位翻转包括选择一个长度为 K 的（连续）子数组，同时将子数组中的每个 0 更改为
// 1，而每个 1 更改为 0
//。
//
// 返回所需的 K 位翻转的最小次数，以便数组没有值为 0 的元素。如果不可能，返回 -1。
//
//
//
// 示例 1：
//
//
// 输入：A = [0,1,0], K = 1
// 输出：2
// 解释：先翻转 A[0]，然后翻转 A[2]。
//
//
// 示例 2：
//
//
// 输入：A = [1,1,0], K = 2
// 输出：-1
// 解释：无论我们怎样翻转大小为 2 的子数组，我们都不能使数组变为 [1,1,1]。
//
//
// 示例 3：
//
//
// 输入：A = [0,0,0,1,0,1,1,0], K = 3
// 输出：3
// 解释：
// 翻转 A[0],A[1],A[2]: A变成 [1,1,1,1,0,1,1,0]
// 翻转 A[4],A[5],A[6]: A变成 [1,1,1,1,1,0,0,0]
// 翻转 A[5],A[6],A[7]: A变成 [1,1,1,1,1,1,1,1]
//
//
//
//
// 提示：
//
//
// 1 <= A.length <= 30000
// 1 <= K <= A.length
//
// Related Topics 贪心算法 Sliding Window
// 👍 83 👎 0

#if 0
int minKBitFlips(int *A, int size, int K) {
    int ans = 0;
    for (int i = 0, offset = 1; i + K < size; i += offset, offset = 1) {
        if (A[i]) continue;
        for (; offset < K && !A[i + offset]; ++offset) {}
        if (offset == K) {
            ans += 1;
            for (int j = i + offset - 1; j >= size - K; --j) {
                A[j] = !A[j];
            }
        } else if (i + offset + K > size) {
            return -1;
        } else {
            ans += 2;
            for (int j = 0; j < offset; ++j) {
                A[i + K + j] = !A[i + K + j];
            }
        }
    }
    for (int i = 2; i <= K; ++i) {
        if (A[size - i] != A[size - 1]) return -1;
    }
    return ans + !A[size - 1];
}
#else
int minKBitFlips(int *A, int size, int K) {
    int diff[size], ans = 0;

    memset(diff, 0, sizeof(diff));
    for (int i = 0, flip = 0; i < size; flip += diff[i++]) {
        if ((A[i] + flip) % 2) continue;
        if (i + K > size) return -1;
        ans++, diff[i] += 1, diff[i + K - 1] -= 1;
    }

    return ans;
}
#endif
