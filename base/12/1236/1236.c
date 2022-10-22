// 你打算利用空闲时间来做兼职工作赚些零花钱。
//
// 这里有 n 份兼职工作，每份工作预计从 startTime[i] 开始到 endTime[i] 结束，报酬为 profit[i]。
//
// 给你一份兼职工作表，包含开始时间 startTime，结束时间 endTime 和预计报酬 profit
// 三个数组，请你计算并返回可以获得的最大报酬。
//
// 注意，时间上出现重叠的 2 份工作不能同时进行。
//
// 如果你选择的工作在时间 X 结束，那么你可以立刻进行在时间 X 开始的下一份工作。
//
//
//
// 示例 1：
//
//
//
// 输入：startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
// 输出：120
// 解释：
// 我们选出第 1 份和第 4 份工作，
// 时间范围是 [1-3]+[3-6]，共获得报酬 120 = 50 + 70。
//
//
// 示例 2：
//
//
//
// 输入：startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
// 输出：150
// 解释：
// 我们选择第 1，4，5 份工作。
// 共获得报酬 150 = 20 + 70 + 60。
//
//
// 示例 3：
//
//
//
// 输入：startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
// 输出：6
//
//
//
//
// 提示：
//
//
// 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
// 1 <= startTime[i] < endTime[i] <= 10^9
// 1 <= profit[i] <= 10^4
//
//
// Related Topics 数组 二分查找 动态规划 排序 👍 222 👎 0

typedef struct {
    int start, end, profit;
} node_t;
int cmp(const void *a, const void *b) {
    node_t *pa = ( node_t * )a, *pb = ( node_t * )b;
    return pa->end < pb->end ? -1 : pa->end > pb->end;
}
int jobScheduling(int *startTime, int size, int *endTime, int endTimeSize, int *profit, int profitSize) {
    int dp[size + 1];
    node_t nodes[size];
    for (int i = 0; i < size; ++i) {
        nodes[i] = (node_t) { startTime[i], endTime[i], profit[i] };
    }
    memset(dp, 0, sizeof(dp));
    qsort(nodes, size, sizeof(node_t), cmp);
    for (int i = 0, l, r, mid; i < size; ++i) {
        for (l = 0, r = i; l <= r;) {
            mid = (l + r) / 2;
            if (nodes[mid].end > nodes[i].start) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        dp[i + 1] = fmax(dp[i], dp[l] + nodes[i].profit);
    }
    return dp[size];
}
