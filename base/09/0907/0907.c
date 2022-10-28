// 给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。
//
// 由于答案可能很大，因此 返回答案模 10^9 + 7 。
//
//
//
// 示例 1：
//
//
// 输入：arr = [3,1,2,4]
// 输出：17
// 解释：
// 子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。
// 最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。
//
// 示例 2：
//
//
// 输入：arr = [11,81,94,43,3]
// 输出：444
//
//
//
//
// 提示：
//
//
// 1 <= arr.length <= 3 * 10⁴
// 1 <= arr[i] <= 3 * 10⁴
//
//
//
//
// Related Topics 栈 数组 动态规划 单调栈 👍 498 👎 0

#define MOD 1000000007
typedef struct {
    int index, sum;
} node_t;
int sumSubarrayMins(int *arr, int size) {
    int ans = 0;
    node_t stack[size + 1];

    stack[0] = (node_t) { -1, 0 };
    for (int i = 0, top = 0; i < size; ++i) {
        for (; stack[top].index >= 0 && arr[stack[top].index] >= arr[i]; --top) {}
        stack[top + 1] = (node_t) { i, (stack[top].sum + arr[i] * (i - stack[top].index)) % MOD };
        ans            = (ans + stack[++top].sum) % MOD;
    }
    return ans;
}
