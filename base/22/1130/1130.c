// 给你一个正整数数组 arr，考虑所有满足以下条件的二叉树：
//
//
// 每个节点都有 0 个或是 2 个子节点。
// 数组 arr 中的值与树的中序遍历中每个叶节点的值一一对应。（知识回顾：如果一个节点有 0 个子节点，那么该节点为叶节点。）
// 每个非叶节点的值等于其左子树和右子树中叶节点的最大值的乘积。
//
//
// 在所有这样的二叉树中，返回每个非叶节点的值的最小可能总和。这个和的值是一个 32 位整数。
//
//
//
// 示例：
//
// 输入：arr = [6,2,4]
// 输出：32
// 解释：
// 有两种可能的树，第一种的非叶节点的总和为 36，第二种非叶节点的总和为 32。
//
//     24            24
//    /  \          /  \
//   12   4        6    8
//   /  \               / \
// 6    2             2   4
//
//
//
// 提示：
//
//
// 2 <= arr.length <= 40
// 1 <= arr[i] <= 15
// 答案保证是一个 32 位带符号整数，即小于 2^31。
//
// Related Topics 栈 贪心 动态规划 单调栈
// 👍 177 👎 0

#define MAXN 40

int dp[MAXN][MAXN], max[MAXN][MAXN];
int mctFromLeaf(int arr[], int beg, int end) {
    if (dp[beg][end] != -1) return dp[beg][end];
    if (beg == end) return dp[beg][end] = 0;
    int ans = INT32_MAX;
    for (int i = beg; i < end; ++i) {
        int l = mctFromLeaf(arr, beg, i), r = mctFromLeaf(arr, i + 1, end);
        int tmp = l + r + max[beg][i] * max[i + 1][end];
        if (ans > tmp) ans = tmp;
    }
    return dp[beg][end] = ans;
}
int mctFromLeafValues(int *arr, int size) {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < size; ++i) {
        max[i][i] = arr[i];
        for (int j = 0; j < i; ++j) {
            max[j][i] = fmax(arr[i], max[j][i - 1]);
        }
    }
    return mctFromLeaf(arr, 0, size - 1);
}
