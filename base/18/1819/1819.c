// 给你一个由正整数组成的数组 nums 。
//
// 数字序列的 最大公约数 定义为序列中所有整数的共有约数中的最大整数。
//
//
// 例如，序列 [4,6,16] 的最大公约数是 2 。
//
//
// 数组的一个 子序列 本质是一个序列，可以通过删除数组中的某些元素（或者不删除）得到。
//
//
// 例如，[2,5,10] 是 [1,2,1,2,4,1,5,10] 的一个子序列。
//
//
// 计算并返回 nums 的所有 非空 子序列中 不同 最大公约数的 数目 。
//
//
//
// 示例 1：
//
//
// 输入：nums = [6,10,3]
// 输出：5
// 解释：上图显示了所有的非空子序列与各自的最大公约数。
// 不同的最大公约数为 6 、10 、3 、2 和 1 。
//
//
// 示例 2：
//
//
// 输入：nums = [5,15,40,5,6]
// 输出：7
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 2 * 105
//
// Related Topics 数学
// 👍 28 👎 0

#define MAXN 200000
int gcd(int a, int b) {
    for (int tmp; b; tmp = a % b, a = b, b = tmp) {}
    return a;
}
int countDifferentSubsequenceGCDs(int *nums, int size) {
    int max = 0, min_g[MAXN + 1] = { 0 };
    bool exists[MAXN + 1] = { false };
    for (int i = 0; i < size; ++i) {
        exists[nums[i]] = true;
        if (max < nums[i]) max = nums[i];
    }

    int ans = 0;
    for (int i = 1; i <= max; ++i) {
        if (min_g[i]) continue;
        for (int j = i; j <= max; j += i) {
            if (!exists[j]) continue;
            min_g[i] = gcd(min_g[i] ? min_g[i] : j, j);
            if (min_g[i] == i) break;
        }
        if (min_g[i] == i) {
            ans++;
        } else if (min_g[i]) {
            if (!min_g[min_g[i]]) ans++;
            for (int j = i + i; j <= max; j += i) {
                if (j == min_g[i] || j % min_g[i] != 0) min_g[j] = min_g[i];
            }
        }
    }

    return ans;
}