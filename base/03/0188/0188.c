// 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
//
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
//
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//
//
//
// 示例 1：
//
//
// 输入：k = 2, prices = [2,4,1]
// 输出：2
// 解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
//
// 示例 2：
//
//
// 输入：k = 2, prices = [3,2,6,5,0,3]
// 输出：7
// 解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
//     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3
//。
//
//
//
// 提示：
//
//
// 0 <= k <= 109
// 0 <= prices.length <= 1000
// 0 <= prices[i] <= 1000
//
// Related Topics 动态规划
// 👍 370 👎 0

typedef struct {
    int min, max;
} node_t;

int dp[500][500][500];
int dfs(node_t nodes[], int left, int right, int k) {
    int ans = 0;
    if (dp[k - 1][left][right]) return dp[k - 1][left][right];
    if (k == 1) {
        int min = nodes[left].min, max = nodes[left].max;
        for (int i = left + 1; i <= right; i++) {
            if (min > nodes[i].min) {
                if (ans < max - min) ans = max - min;
                min = nodes[i].min, max = nodes[i].max;
            } else if (max < nodes[i].max) {
                max = nodes[i].max;
            }
        }
        if (ans < max - min) ans = max - min;
    } else {
        for (int i = left; i + k - 1 <= right; ++i) {
            int l = dfs(nodes, left, i, 1), r = dfs(nodes, i + 1, right, k - 1);
            if (ans < l + r) ans = l + r;
        }
    }

    return dp[k - 1][left][right] = ans;
}
int maxProfit(int K, int *prices, int size) {
    if (!K || size < 2) return 0;

    int len = 0, ans = 0;
    node_t nodes[size / 2];

    for (int i = 0, have = false; i < size; ++i) {
        if (have && (i + 1 == size || prices[i] >= prices[i + 1])) {
            ans += prices[i] - nodes[len].min;
            have = false, nodes[len++].max = prices[i];
        } else if (!have && i + 1 < size && prices[i] < prices[i + 1]) {
            have = true, nodes[len].min = prices[i];
        }
    }

    if (K >= len) return ans;

    memset(dp, 0, sizeof(dp));
    return dfs(nodes, 0, len - 1, K);
}
