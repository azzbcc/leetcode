// 给出一些不同颜色的盒子，盒子的颜色由数字表示，即不同的数字表示不同的颜色。
// 你将经过若干轮操作去去掉盒子，直到所有的盒子都去掉为止。每一轮你可以移除具有相同颜色的连续 k 个盒子（k >=
// 1），这样一轮之后你将得到 k*k 个积分 。 当你将所有盒子都去掉之后，求你能获得的最大积分和。
//
//
//
// 示例：
//
// 输入：boxes = [1,3,2,2,2,3,4,3,1]
// 输出：23
// 解释：
// [1, 3, 2, 2, 2, 3, 4, 3, 1]
// ----> [1, 3, 3, 4, 3, 1] (3*3=9 分)
// ----> [1, 3, 3, 3, 1] (1*1=1 分)
// ----> [1, 1] (3*3=9 分)
// ----> [] (2*2=4 分)
//
//
//
//
// 提示：
//
//
// 1 <= boxes.length <= 100
// 1 <= boxes[i] <= 100
//
// Related Topics 深度优先搜索 动态规划
// 👍 228 👎 0
#define MAXN 100

struct st_node {
    uint8_t val, count;
} nodes[MAXN];
uint8_t node_size = 0;
int max(int a, int b) {
    return a > b ? a : b;
}
int cal(int size, int dp[size][size][size], int l, int r, int n) {
    if (l > r) return 0;
    if (!dp[l][r][n]) {
        dp[l][r][n] = cal(size, dp, l + 1, r, 0) + (n + nodes[l].count) * (n + nodes[l].count);
        for (int i = l + 1; i <= r; i++) {
            if (nodes[i].val != nodes[l].val) continue;
            dp[l][r][n] = max(dp[l][r][n], cal(size, dp, l + 1, i - 1, 0) + cal(size, dp, i, r, n + nodes[l].count));
        }
    }
    return dp[l][r][n];
}
int removeBoxes(int *boxes, int boxesSize) {
    // data initial
    node_size = 1, nodes[0].val = boxes[0], nodes[0].count = 1;
    for (int i = 1; i < boxesSize; ++i) {
        if (boxes[i] == nodes[node_size - 1].val) {
            nodes[node_size - 1].count += 1;
        } else {
            node_size += 1;
            nodes[node_size - 1].val = boxes[i], nodes[node_size - 1].count = 1;
        }
    }

    int dp[node_size][node_size][node_size];

    // calculate
    memset(dp, 0, sizeof(dp));
    return cal(node_size, dp, 0, node_size - 1, 0);
}
