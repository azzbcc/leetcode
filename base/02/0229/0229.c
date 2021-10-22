// 给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
//
//
//
//
//
// 示例 1：
//
//
// 输入：[3,2,3]
// 输出：[3]
//
// 示例 2：
//
//
// 输入：nums = [1]
// 输出：[1]
//
//
// 示例 3：
//
//
// 输入：[1,1,1,3,3,2,2,2]
// 输出：[1,2]
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 5 * 10⁴
// -10⁹ <= nums[i] <= 10⁹
//
//
//
//
// 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。
// Related Topics 数组 哈希表 计数 排序 👍 468 👎 0

int *majorityElement(int *nums, int size, int *returnSize) {
    int *p[2], v[2] = { 0 }, c[2] = { 0 };
    int *ans = malloc(2 * sizeof(int));
    for (int i = 0; i < size; ++i) {
        if (v[0] && *p[0] == nums[i]) {
            v[0]++;
        } else if (v[1] && *p[1] == nums[i]) {
            v[1]++;
        } else if (!v[0]) {
            v[0]++, p[0] = &nums[i];
        } else if (!v[1]) {
            v[1]++, p[1] = &nums[i];
        } else {
            v[0]--, v[1]--;
        }
    }
    for (int i = 0; i < size; ++i) {
        if (v[0] && *p[0] == nums[i]) c[0]++;
        if (v[1] && *p[1] == nums[i]) c[1]++;
    }
    *returnSize = 0;
    if (c[0] > size / 3) ans[(*returnSize)++] = *p[0];
    if (c[1] > size / 3) ans[(*returnSize)++] = *p[1];
    return ans;
}