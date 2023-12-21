// 给你一个长度为 n 下标从 0 开始的整数数组 maxHeights 。
//
// 你的任务是在坐标轴上建 n 座塔。第 i 座塔的下标为 i ，高度为 heights[i] 。
//
// 如果以下条件满足，我们称这些塔是 美丽 的：
//
//
// 1 <= heights[i] <= maxHeights[i]
// heights 是一个 山脉 数组。
//
//
// 如果存在下标 i 满足以下条件，那么我们称数组 heights 是一个 山脉 数组：
//
//
// 对于所有 0 < j <= i ，都有 heights[j - 1] <= heights[j]
// 对于所有 i <= k < n - 1 ，都有 heights[k + 1] <= heights[k]
//
//
// 请你返回满足 美丽塔 要求的方案中，高度和的最大值 。
//
//
//
// 示例 1：
//
//
// 输入：maxHeights = [5,3,4,1,1]
// 输出：13
// 解释：和最大的美丽塔方案为 heights = [5,3,3,1,1] ，这是一个美丽塔方案，因为：
// - 1 <= heights[i] <= maxHeights[i]
// - heights 是个山脉数组，峰值在 i = 0 处。
// 13 是所有美丽塔方案中的最大高度和。
//
// 示例 2：
//
//
// 输入：maxHeights = [6,5,3,9,2,7]
// 输出：22
// 解释： 和最大的美丽塔方案为 heights = [3,3,3,9,2,2] ，这是一个美丽塔方案，因为：
// - 1 <= heights[i] <= maxHeights[i]
// - heights 是个山脉数组，峰值在 i = 3 处。
// 22 是所有美丽塔方案中的最大高度和。
//
// 示例 3：
//
//
// 输入：maxHeights = [3,2,5,5,2,3]
// 输出：18
// 解释：和最大的美丽塔方案为 heights = [2,2,5,5,2,2] ，这是一个美丽塔方案，因为：
// - 1 <= heights[i] <= maxHeights[i]
// - heights 是个山脉数组，最大值在 i = 2 处。
// 注意，在这个方案中，i = 3 也是一个峰值。
// 18 是所有美丽塔方案中的最大高度和。
//
//
//
//
// 提示：
//
//
// 1 <= n == maxHeights <= 10⁵
// 1 <= maxHeights[i] <= 10⁹
//
//
// Related Topics 栈 数组 单调栈 👍 57 👎 0

#define MAX 100000
typedef struct {
    int top;
    int data[MAX];
} stack_t;
int stack_top(stack_t *s) {
    return s->data[s->top];
}
long long maximumSumOfHeights(int *maxHeights, int size) {
    stack_t stack[2] = { { -1 }, { -1 } };
    long long prefix[size], suffix[size], ans = 0;

    for (int i = 0; i < size; i++) {
        for (; stack[0].top >= 0 && maxHeights[i] < maxHeights[stack_top(&stack[0])]; --stack[0].top) {}
        if (stack[0].top >= 0) {
            prefix[i] = prefix[stack_top(&stack[0])] + ( long long )(i - stack_top(&stack[0])) * maxHeights[i];
        } else {
            prefix[i] = ( long long )(i + 1) * maxHeights[i];
        }
        stack[0].data[++stack[0].top] = i;
    }
    for (int i = size - 1; i >= 0; --i) {
        for (; stack[1].top >= 0 && maxHeights[i] < maxHeights[stack_top(&stack[1])]; --stack[1].top) {}
        if (stack[1].top >= 0) {
            suffix[i] = suffix[stack_top(&stack[1])] + ( long long )(stack_top(&stack[1]) - i) * maxHeights[i];
        } else {
            suffix[i] = ( long long )(size - i) * maxHeights[i];
        }
        stack[1].data[++stack[1].top] = i, ans = fmax(ans, prefix[i] + suffix[i] - maxHeights[i]);
    }
    return ans;
}