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

#if 0
typedef struct {
    int min, max;
} node_t;

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

    int one[len][len];
    for (int i = 0; i < len; ++i) {
        int min = nodes[i].min, max = nodes[i].max;
        one[i][i] = max - min;
        for (int j = i + 1; j < len; ++j) {
            one[i][j] = one[i][j - 1];
            if (min > nodes[j].min) {
                min = nodes[j].min, max = nodes[j].max;
            } else if (max < nodes[j].max) {
                max = nodes[j].max;
            }
            if (one[i][j] < max - min) one[i][j] = max - min;
        }
    }

    int dp[2][len], last = 0;
    // dp[now][len] = max(dp[last][k] + one[k+1][len], ..., dp[last][len-1] + one[len][len])

    memcpy(dp[last], one[0], sizeof(one[0]));
    for (int now = 1, k = 1; k < K; k++, last = now, now = 1 - now) {
        for (int i = len - 1; i >= k; --i) {
            dp[now][i] = dp[last][k - 1] + one[k][i];
            for (int j = k; j < i; ++j) {
                if (dp[now][i] < dp[last][j] + one[j + 1][i]) {
                    dp[now][i] = dp[last][j] + one[j + 1][i];
                }
            }
        }
    }

    return dp[last][len - 1];
}
#elif 0
int max(int a, int b) {
    return a > b ? a : b;
}
int maxProfit(int K, int *prices, int size) {
    if (K > size / 2) K = size / 2;
    if (!K) return 0;

    int dp[K + 1][2];

    for (int i = 0; i <= K; ++i) {
        dp[i][0] = 0, dp[i][1] = -*prices;
    }
    for (int i = 1; i < size; ++i) {
        for (int j = K; j; --j) {
            dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
            dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]);
        }
    }

    return dp[K][0];
}
#else
// [一种基于wqs二分的做法](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/yi-chong-ji-yu-wqs-er-fen-de-you-xiu-zuo-x36r)

int max(int a, int b) {
    return a > b ? a : b;
}
int maxProfit(int K, int *prices, int size) {
    if (size <= 0) return 0;

    // 二分查找的上下界
    int left = 1, right = 0;
    for (int i = 0; i < size; ++i) {
        if (right < prices[i]) right = prices[i];
    }

    // 存储答案，如果值为 -1 表示二分查找失败
    int ans = -1;
    while (left <= right) {
        // 二分得到当前的斜率（手续费）
        int c = (left + right) / 2;

        // 使用与 714 题相同的动态规划方法求解出最大收益以及对应的交易次数
        int buyCount = 0, sellCount = 0;
        int buy = -prices[0], sell = 0;

        for (int i = 1; i < size; ++i) {
            if (sell - prices[i] >= buy) {
                buy      = sell - prices[i];
                buyCount = sellCount;
            }
            if (buy + prices[i] - c >= sell) {
                sell      = buy + prices[i] - c;
                sellCount = buyCount + 1;
            }
        }

        // 如果交易次数大于等于 k，那么可以更新答案
        // 这里即使交易次数严格大于 k，更新答案也没有关系，因为总能二分到等于 k 的
        if (sellCount >= K) {
            // 别忘了加上 kc
            ans  = sell + K * c;
            left = c + 1;
        } else {
            right = c - 1;
        }
    }

    // 如果二分查找失败，说明交易次数的限制不是瓶颈
    // 可以看作交易次数无限，直接使用贪心方法得到答案
    if (ans == -1) {
        ans = 0;
        for (int i = 1; i < size; ++i) {
            ans += max(prices[i] - prices[i - 1], 0);
        }
    }

    return ans;
}
#endif
