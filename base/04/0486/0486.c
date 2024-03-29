//给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2
//继续从剩余数组任意一端拿取分数，然后玩家 1 拿，…… 。每次一个玩家
//只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。
//
// 给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。
//
//
//
// 示例 1：
//
// 输入：[1, 5, 2]
//输出：False
//解释：一开始，玩家1可以从1和2中进行选择。
//如果他选择 2（或者 1 ），那么玩家 2 可以从 1（或者 2 ）和 5 中进行选择。如果玩家 2 选择了 5 ，那么玩家 1 则只剩下
// 1（或者 2 ） 可选。 所以，玩家 1 的最终分数为 1 + 2 = 3，而玩家 2 为 5 。 因此，玩家 1 永远不会成为赢家，返回 False
// 。
//
//
// 示例 2：
//
// 输入：[1, 5, 233, 7]
//输出：True
//解释：玩家 1 一开始选择 1 。然后玩家 2 必须从 5 和 7 中进行选择。无论玩家 2 选择了哪个，玩家 1 都可以选择 233 。
//     最终，玩家 1（234 分）比玩家 2（12 分）获得更多的分数，所以返回 True，表示玩家 1 可以成为赢家。
//
//
//
//
// 提示：
//
//
// 1 <= 给定的数组长度 <= 20.
// 数组里所有分数都为非负数且不会大于 10000000 。
// 如果最终两个玩家的分数相等，那么玩家 1 仍为赢家。
//
// Related Topics 极小化极大 动态规划
// 👍 235 👎 0
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int initiative(int *, int, int);

int gote(int *nums, int size, int uncle) {
    if (size == 1) return 0;

    int left = initiative(nums + 1, size - 1, INT32_MAX);
    if (left < uncle) return uncle;

    int right = initiative(nums, size - 1, left);

    return MIN(left, right);
}
int initiative(int *nums, int size, int uncle) {
    if (size == 1) return *nums;

    int left = gote(nums + 1, size - 1, 0) + nums[0];
    if (left > uncle) return uncle;

    int right = gote(nums, size - 1, left - nums[size - 1]) + nums[size - 1];

    return MAX(left, right);
}

bool PredictTheWinner_1(int *nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; sum += nums[i++]) {}

    return sum <= 2 * initiative(nums, numsSize, INT32_MAX);
}

bool PredictTheWinner_2(int *nums, int numsSize) {
    int dp[numsSize][numsSize][2];

    for (int i = 0; i < numsSize; ++i) {
        dp[i][i][0] = nums[i], dp[i][i][1] = 0;
    }
    for (int len = 1; len < numsSize; ++len) {
        for (int i = 0; i + len < numsSize; ++i) {
            dp[i][i + len][0] = MAX(nums[i] + dp[i + 1][i + len][1], nums[i + len] + dp[i][i + len - 1][1]);
            dp[i][i + len][1] = MIN(dp[i + 1][i + len][0], dp[i][i + len - 1][0]);
        }
    }
    return dp[0][numsSize - 1][0] >= dp[0][numsSize - 1][1];
}

bool (*PredictTheWinner)(int *nums, int numsSize) = PredictTheWinner_2;