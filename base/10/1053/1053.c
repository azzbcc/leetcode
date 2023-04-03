// 给你一个正整数数组 arr（可能存在重复的元素），请你返回可在 一次交换（交换两数字 arr[i] 和 arr[j] 的位置）后得到的、
// 按字典序排列小于 arr 的最大排列。
//
// 如果无法这么操作，就请返回原数组。
//
//
//
// 示例 1：
//
//
// 输入：arr = [3,2,1]
// 输出：[3,1,2]
// 解释：交换 2 和 1
//
//
// 示例 2：
//
//
// 输入：arr = [1,1,5]
// 输出：[1,1,5]
// 解释：已经是最小排列
//
//
// 示例 3：
//
//
// 输入：arr = [1,9,4,6,7]
// 输出：[1,7,4,6,9]
// 解释：交换 9 和 7
//
//
//
//
// 提示：
//
//
// 1 <= arr.length <= 10⁴
// 1 <= arr[i] <= 10⁴
//
//
// Related Topics 贪心 数组 👍 81 👎 0

int *prevPermOpt1(int *arr, int size, int *returnSize) {
    int a, b, *ans = malloc((*returnSize = size) * sizeof(int));
    memcpy(ans, arr, size * sizeof(int));
    for (a = size - 2; a >= 0; --a) {
        if (ans[a] > ans[a + 1]) break;
    }
    if (b = a + 1, a < 0) return ans;
    for (int i = b; i < size; ++i) {
        if (ans[i] < ans[a] && ans[i] > ans[b]) b = i;
    }
    for (int tmp = ans[a]; tmp != ans[b]; ans[a] = ans[b], ans[b] = tmp) {}
    return ans;
}
