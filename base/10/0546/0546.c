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

    // dp[j][i] = max(dp[j][i-1]+K(i), dp[j][m-1]+dp[m+1][i-1]+K(m+i), ...)
    int dp[MAXN][MAXN] = { 0 };
    int repeats[MAXN] = { 0 }, records[MAXN][MAXN / 2] = { 0 };

    for (int i = 0; i < node_size; ++i) {
        int offset = nodes[i].val - 1, repeat = repeats[offset]++;
        records[offset][repeat] = i, dp[i][i] = nodes[i].count * nodes[i].count;
        for (int j = i - 1, tmp_repeat = repeat; j >= 0; --j) {
            dp[j][i] = dp[j][i - 1] + dp[i][i];
            if (tmp_repeat) tmp_repeat -= j == records[offset][tmp_repeat - 1];
            for (uint64_t m = 1; m < (1 << (repeat - tmp_repeat)); ++m) {
                int mj = 0, count = nodes[i].count, last = i;
                for (int k = repeat - 1; k >= tmp_repeat; --k) {
                    if (m & 1 << (k - tmp_repeat)) {
                        int pos = records[offset][k];
                        mj += dp[pos + 1][last - 1];
                        last = pos, count += nodes[pos].count;
                    }
                }
                int now = mj + count * count;
                if (last > j) now += dp[j][last - 1];
                if (dp[j][i] < now) dp[j][i] = now;
            }
        }
    }

    return dp[0][node_size - 1];
}
