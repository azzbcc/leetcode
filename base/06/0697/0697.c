// 给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。
//
// 你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
//
//
//
// 示例 1：
//
//
// 输入：[1, 2, 2, 3, 1]
// 输出：2
// 解释：
// 输入数组的度是2，因为元素1和2的出现频数最大，均为2.
// 连续子数组里面拥有相同度的有如下所示:
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// 最短连续子数组[2, 2]的长度为2，所以返回2.
//
//
// 示例 2：
//
//
// 输入：[1,2,2,3,1,4,2]
// 输出：6
//
//
//
//
// 提示：
//
//
// nums.length 在1到 50,000 区间范围内。
// nums[i] 是一个在 0 到 49,999 范围内的整数。
//
// Related Topics 数组
// 👍 263 👎 0

#if 0
#define MAXN 50000
int findShortestSubArray(int *nums, int size) {
    int max = 0, ans = size;
    int times[MAXN] = { 0 }, first[MAXN], last[MAXN];
    memset(first, -1, sizeof(first));
    for (int i = 0, num; i < size; ++i) {
        num = nums[i];
        if (-1 == first[num]) first[num] = i;
        times[num]++, last[num] = i;
        if (max < times[num]) max = times[num];
    }
    for (int i = 0; i < MAXN; ++i) {
        if (max != times[i]) continue;
        if (ans > last[i] - first[i]) ans = last[i] - first[i];
    }
    return ans + 1;
}
#else
#define MAXN 50000
int findShortestSubArray(int *nums, int size) {
    int max = 0, ans = 0;
    int times[MAXN] = { 0 }, first[MAXN];

    for (int i = 0, num; i < size; ++i) {
        if (times[num = nums[i]]++) {
            if (max < times[num]) {
                max = times[num], ans = i - first[num];
            } else if (max == times[num]) {
                if (ans > i - first[num]) ans = i - first[num];
            }
        } else {
            first[num] = i;
        }
    }
    return ans + 1;
}
#endif